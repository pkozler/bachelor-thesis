unit StringTokenizerUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, StrUtils, StringUnit;

type
  (**
   * The string tokenizer class allows an application to break a string into tokens.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  StringTokenizer = class(Object_)
    private
      var
        tokens: array of ansiString;
        tokenCounter: longInt;
    public
      constructor create(str: String_);
      constructor create(str: String_; delim: String_);
      function countTokens() : longInt;
      function hasMoreTokens() : boolean;
      function nextToken() : String_;
  end;

implementation

uses
  SysUtils;

(**
 * Constructs a string tokenizer for the specified string.
 *
 * @param str a string to be parsed.
 *)
constructor StringTokenizer.create(str: String_);
begin
  self.create(str, ' \t\n\r\f');
end;

(**
 * Constructs a string tokenizer for the specified string.
 *
 * @param str a string to be parsed.
 * @param delim the delimiters.
 *)
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

(**
 * Calculates the number of times that this tokenizer's nextToken method can
 * be called before it generates an exception.
 *
 * @return the number of tokens remaining in the string using the current
 * delimiter set.
 *)
function StringTokenizer.countTokens() : longInt;
begin
  countTokens := length(tokens);
end;

(**
 * Tests if there are more tokens available from this tokenizer's string.
 *
 * @return true if and only if there is at least one token in the string
 * after the current position; false otherwise.
 *)
function StringTokenizer.hasMoreTokens() : boolean;
begin
  hasMoreTokens := (countTokens() <> 0);
end;

(**
 * Returns the next token from this string tokenizer.
 *
 * @return the next token from this string tokenizer.
 *)
function StringTokenizer.nextToken() : String_;
var
  i: longInt;
begin
  i := tokenCounter;
  inc(tokenCounter);
  nextToken := tokens[i];
end;

end.

