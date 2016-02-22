unit StringTokenizerUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, StrUtils, StringUnit;

type
  StringTokenizer = class
    private
      var
        tokens: array of ansiString;
        tokenCounter: longInt;
    public
      constructor create(str: String_);
      constructor create(str: String_; delim: String_);
      destructor destroy(); override;
      function countTokens() : longInt;
      function hasMoreTokens() : boolean;
      function nextToken() : String_;
  end;

implementation

uses
  SysUtils;

constructor StringTokenizer.create(str: String_);
begin
  self.create(str, ' \t\n\r\f');
end;

constructor StringTokenizer.create(str: String_; delim: String_);
var
  strStr, delimStr: ansiString;
  count, len, i, tmp, index: longInt;
begin
  tokenCounter := 0;
  count := 1;
  strStr := str.toString();
  delimStr := delim.toString();
  len := length(strStr);

  for i := 1 to len do begin
    if ansiContainsStr(delimStr, strStr[i]) then begin
      inc(count);
    end;
  end;

  setLength(tokens, count);
  index := 0;
  tmp := 1;

  for i := 1 to len do begin
    if ansiContainsStr(delimStr, strStr[i]) then begin
       tokens[index] := copy(strStr, tmp, i - tmp);
       tmp := i;
       inc(index);
    end;
  end;

  tokens[index] := copy(strStr, tmp, i - tmp);
end;

destructor StringTokenizer.destroy();
begin
  inherited;
end;

function StringTokenizer.countTokens() : longInt;
begin
  countTokens := length(tokens);
end;

function StringTokenizer.hasMoreTokens() : boolean;
begin
  hasMoreTokens := (countTokens() <> 0);
end;

function StringTokenizer.nextToken() : String_;
var
  i: longInt;
begin
  i := tokenCounter;
  inc(tokenCounter);
  nextToken := tokens[i];
end;

end.

