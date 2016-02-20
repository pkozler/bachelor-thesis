unit StringTokenizerUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, StrUtils, StringUnit;

type
  StringTokenizer = class
    private
      var
        tokens: TStringList;
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
  strStr: ansiString;
  delimStr: ansiString;
  len, i: longInt;
begin
  tokenCounter := 0;
  tokens := TStringList.create();

  strStr := str.toString();
  delimStr := delim.toString();
  // TODO rozdelit retezec na tokeny a vlozit do listu
end;

destructor StringTokenizer.destroy();
begin
  freeAndNil(tokens);
  inherited;
end;

function StringTokenizer.countTokens() : longInt;
begin
  countTokens := tokens.count;
end;

function StringTokenizer.hasMoreTokens() : boolean;
begin
  hasMoreTokens := (countTokens() <> 0);
end;

function StringTokenizer.nextToken() : String_;
var
  index: longInt;
begin
  index := tokenCounter;
  inc(tokenCounter);
  nextToken := tokens[index];
end;

end.

