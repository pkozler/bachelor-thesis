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
        // string token array
        tokens: array of ansiString;
        // current position in the token array
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
  self.create(str, #32#9#10#11#12#13);
end;

(**
 * Constructs a string tokenizer for the specified string.
 *
 * @param str a string to be parsed.
 * @param delim the delimiters.
 *)
constructor StringTokenizer.create(str: String_; delim: String_);
var
  strStr, delimStr, tmpStr: ansiString;
  count, len, i, tmp, index: longInt;
begin
  tokenCounter := 0;
  count := 1;
  strStr := str.strProperty;
  delimStr := delim.strProperty;
  len := length(strStr);

  // determining the greatest possible length of the token array
  for i := 1 to len do begin
    if ansiContainsStr(delimStr, strStr[i]) then begin
      inc(count);
    end;
  end;

  // creating the token array with the determined length
  setLength(tokens, count);
  index := 0;
  tmp := 1;

  // iterating over the characters in the string to find delimiters
  for i := 1 to len do begin
    // the delimiter was found
    if ansiContainsStr(delimStr, strStr[i]) then begin
       // copying all the character in the string from the current offset to the delimiter position
       tmpStr := copy(strStr, tmp, i - tmp);

       // inserting the non-empty string into the token array
       if length(tmpStr) > 0 then begin
          tokens[index] := tmpStr;
          inc(index);
       end;

       // increasing the offset by the current position in the string
       tmp := i + 1;
    end;
  end;

  // copying the rest of the characters
  tmpStr := copy(strStr, tmp, i - tmp + 1);

  // inserting the string into the token array if not empty
  if length(tmpStr) > 0 then begin
     tokens[index] := tmpStr;
     inc(index);
  end;

  // resizing the token array with the determined length
  setLength(tokens, index);
end;

(**
 * Calculates the number of times that this tokenizer's nextToken method can
 * be called before it causes an error.
 *
 * @return the number of tokens remaining in the string using the current
 * delimiter set.
 *)
function StringTokenizer.countTokens() : longInt;
begin
  countTokens := length(tokens) - tokenCounter;
end;

(**
 * Tests if there are more tokens available from this tokenizer's string.
 *
 * @return true if and only if there is at least one token in the string
 * after the current position; false otherwise.
 *)
function StringTokenizer.hasMoreTokens() : boolean;
begin
  hasMoreTokens := (countTokens() > 0);
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

