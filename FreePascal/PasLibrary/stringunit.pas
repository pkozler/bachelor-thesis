unit StringUnit;

{$mode objfpc}{$H+}

interface

type
  String_ = class;

  (**
   * Class Object is the root of the class hierarchy.
   *)
  Object_ = class
    public
      function equals_(obj: Object_) : boolean; virtual;
      function toString_() : String_; virtual;
      function equals(obj: TObject) : boolean; override;
      function toString() : ansiString; override;
  end;

  (**
   * This abstract class imposes a total ordering on the objects of each class that implements it.
   *)
  Comparable = class(Object_)
    public
      (**
       * Compares this object with the specified object for order.
       *
       * @param o the object to be compared.
       * @return a negative integer, zero, or a positive integer as this object
       * is less than, equal to, or greater than the specified object.
       *)
      function compareTo(o: Object_) : longInt; virtual; abstract;
  end;

  (**
   * A comparison function, which imposes a total ordering on some collection of objects.
   *)
  Comparator = class(Object_)
    public
      (**
       * Compares its two arguments for order.
       *
       * @param o1 the first object to be compared.
       * @param o2 the second object to be compared.
       * @return a negative integer, zero, or a positive integer as the
       * first argument is less than, equal to, or greater than the second.
       *)
      function compare(o1, o2: Object_) : longInt; virtual; abstract;
  end;

  (**
   * The String class represents character strings.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  String_ = class(Comparable)
    private
      var str: ansiString;
    public
      property strProperty: ansiString read str;
      constructor create(bytes: array of shortInt);
      constructor create(bytes: array of shortInt; offset: longInt; length: longInt);
      constructor create(original: ansiString);
      function compareTo(anotherString: Object_) : longInt; override;
      function equals_(anObject: Object_) : boolean; override;
      function substring(beginIndex: longInt) : String_;
      function substring(beginIndex: longInt; endIndex: longInt) : String_;
      function indexOf(ch: longInt) : longInt;
      function indexOf(ch: longInt; fromIndex: longInt) : longInt;
      function indexOf(s: String_) : longInt;
      function indexOf(s: String_; fromIndex: longInt) : longInt;
      function length() : longInt;
      function trim() : String_;
      function toLowerCase() : String_;
      function toUpperCase() : String_;
      function charAt(index: longInt) : ansiChar;
      function replace(oldChar: ansiChar; newChar: ansiChar) : String_;
      function startsWith(prefix: String_) : boolean;
      function endsWith(suffix: String_) : boolean;
      function isEmpty() : boolean;
      function toString_() : String_; override;
  end;

operator := (original: ansiString) s: String_;

implementation

uses
  SysUtils, StrUtils;

(**
 * Indicates whether some other object is "equal to" this one.
 *
 * @param obj the reference object with which to compare.
 * @return true if this object is the same as the obj argument; false otherwise.
 *)
function Object_.equals_(obj: Object_) : boolean;
begin
  equals_ := self = obj;
end;

(**
 * Returns a string representation of the object.
 *
 * @return a string representation of the object.
 *)
function Object_.toString_() : String_;
begin
  toString_ := String_.create(inherited toString());
end;

function Object_.equals(obj: TObject) : boolean;
begin
  equals := self.equals_(Object_(obj));
end;

function Object_.toString() : ansiString;
begin
  toString := toString_().str;
end;

(**
 * Constructs a new String by decoding the specified array of bytes using
 * the ANSI charset.
 *
 * @param bytes The bytes to be decoded into characters
 *)
constructor String_.create(bytes: array of shortInt);
begin
  setString(str, @bytes[0], System.length(bytes));
end;

(**
 * Constructs a new String by decoding the specified subarray of bytes using
 * the ANSI charset.
 *
 * @param bytes The bytes to be decoded into characters
 * @param offset The index of the first byte to decode
 * @param length The number of bytes to decode
 *)
constructor String_.create(bytes: array of shortInt; offset: longInt; length: longInt);
begin
  setString(str, @bytes[offset], length);
end;

(**
 * Initializes a newly created String object so that it represents the same
 * sequence of characters as the argument; in other words, the inner string of the
 * newly created String object is a copy of the argument string.
 *
 * @param original A String
 *)
constructor String_.create(original: ansiString);
begin
  str := original;
end;

(**
 * Compares two strings lexicographically.
 *
 * @param anotherString the String to be compared.
 * @return the value 0 if the argument string is equal to this string; a
 * value less than 0 if this string is lexicographically less than the
 * string argument; and a value greater than 0 if this string is
 * lexicographically greater than the string argument.
 *)
function String_.compareTo(anotherString: Object_) : longInt;
begin
  compareTo := ansiCompareStr(str, (anotherString as String_).str);
end;

(**
 * Compares this string to the specified object.
 *
 * @param anObject The object to compare this String against
 * @return true if the given object represents a String equivalent to this
 * string, false otherwise
 *)
function String_.equals_(anObject: Object_) : boolean;
begin
  if anObject = nil then begin
    exit(false);
  end;

  if typeOf(self) <> typeOf(anObject) then begin
    exit(false);
  end;

  equals_ := (ansiCompareStr(self.str, (anObject as String_).str) = 0);
end;

(**
 * Returns a new string that is a substring of this string.
 *
 * @param beginIndex the beginning index, inclusive.
 * @return the specified substring.
 *)
function String_.substring(beginIndex: longInt) : String_;
begin
  substring := substring(beginIndex, System.length(str));
end;

(**
 * Returns a new string that is a substring of this string.
 *
 * @param beginIndex the beginning index, inclusive.
 * @param endIndex the ending index, exclusive.
 * @return the specified substring.
 *)
function String_.substring(beginIndex: longInt; endIndex: longInt) : String_;
var
  s: String_;
begin
  s := String_.create(copy(str, beginIndex + 1, endIndex - beginIndex));
  substring := s;
end;

(**
 * Returns the index within this string of the first occurrence of the
 * specified character.
 *
 * @param ch a character (Unicode code point).
 * @return the index of the first occurrence of the character in the
 * character sequence represented by this object, or -1 if the character
 * does not occur.
 *)
function String_.indexOf(ch: longInt) : longInt;
begin
  indexOf := indexOf(ch, 0);
end;

(**
 * Returns the index within this string of the first occurrence of the
 * specified character, starting the search at the specified index.
 *
 * @param ch a character (Unicode code point).
 * @param fromIndex the index to start the search from.
 * @return the index of the first occurrence of the character in the
 * character sequence represented by this object that is greater than or
 * equal to fromIndex, or -1 if the character does not occur.
 *)
function String_.indexOf(ch: longInt; fromIndex: longInt) : longInt;
var
  substr: ansiString;
  i: longInt;
begin
  substr := copy(str, fromIndex + 1, System.length(str) - fromIndex);
  i := pos(ansiChar(ch), substr) - 1;

  if i < 0 then begin
    exit(-1);
  end;

  indexOf := i + fromIndex;
end;

(**
 * Returns the index within this string of the first occurrence of the
 * specified substring.
 *
 * @param str the substring to search for.
 * @return the index of the first occurrence of the specified substring, or
 * -1 if there is no such occurrence.
 *)
function String_.indexOf(s: String_) : longInt;
begin
  indexOf := indexOf(s, 0);
end;

(**
 * Returns the index within this string of the first occurrence of the
 * specified substring, starting at the specified index.
 *
 * @param str the substring to search for.
 * @param fromIndex the index from which to start the search.
 * @return the index of the first occurrence of the specified substring,
 * starting at the specified index, or -1 if there is no such occurrence.
 *)
function String_.indexOf(s: String_; fromIndex: longInt) : longInt;
var
  substr: ansiString;
  i: longInt;
begin
  substr := copy(str, fromIndex + 1, System.length(str) - fromIndex + 1);
  i := pos(s.str, substr) - 1;

  if i < 0 then begin
    exit(-1);
  end;

  indexOf := i + fromIndex;
end;

(**
 * Returns the length of this string.
 *
 * @return the length of the sequence of characters represented by this
 * object.
 *)
function String_.length() : longInt;
begin
  length := System.length(str);
end;

(**
 * Returns a copy of the string, with leading and trailing whitespace
 * omitted.
 *
 * @return A copy of this string with leading and trailing white space
 * removed, or this string if it has no leading or trailing white space.
 *)
function String_.trim() : String_;
var
  s: String_;
begin
  s := String_.create(SysUtils.trim(str));
  trim := s;
end;

(**
 * Converts all of the characters in this String to lower case using the
 * rules of the default locale.
 *
 * @return the String, converted to lowercase.
 *)
function String_.toLowerCase() : String_;
var
  s: String_;
begin
  s := String_.create(lowerCase(str));
  toLowerCase := s;
end;

(**
 * Converts all of the characters in this String to upper case using the
 * rules of the default locale.
 *
 * @return the String, converted to uppercase.
 *)
function String_.toUpperCase() : String_;
var
  s: String_;
begin
  s.create(upperCase(str));
  toUpperCase := s;
end;

(**
 * Returns the char value at the specified index.
 *
 * @param index the index of the char value.
 * @return the char value at the specified index of this string. The first
 * char value is at index 0.
 *)
function String_.charAt(index: longInt) : ansiChar;
begin
  charAt := str[index + 1];
end;

(**
 * Returns a new string resulting from replacing all occurrences of oldChar
 * in this string with newChar.
 *
 * @param oldChar the old character.
 * @param newChar the new character.
 * @return a string derived from this string by replacing every occurrence
 * of oldChar with newChar.
 *)
function String_.replace(oldChar: ansiChar; newChar: ansiChar) : String_;
begin
  replace := replaceStr(str, oldChar, newChar);
end;

(**
 * Tests if this string starts with the specified prefix.
 *
 * @param prefix the prefix.
 * @return true if the character sequence represented by the argument is a
 * prefix of the character sequence represented by this string; false
 * otherwise. Note also that true will be returned if the argument is an
 * empty string or is equal to this String object as determined by the
 * equals(Object) method.
 *)
function String_.startsWith(prefix: String_) : boolean;
begin
  startsWith := ansiStartsStr(prefix.toString(), str);
end;

(**
 * Tests if this string ends with the specified suffix.
 *
 * @param suffix the suffix.
 * @return true if the character sequence represented by the argument is a
 * suffix of the character sequence represented by this object; false
 * otherwise. Note that the result will be true if the argument is the empty
 * string or is equal to this String object as determined by the
 * equals(Object) method.
 *)
function String_.endsWith(suffix: String_) : boolean;
begin
  endsWith := ansiEndsStr(suffix.toString(), str);
end;

(**
 * Returns true if, and only if, length() is 0.
 *
 * @return true if length() is 0, otherwise false
 *)
function String_.isEmpty() : boolean;
begin
  isEmpty := (self.length() = 0);
end;

(**
 * This object (which is already a string!) is itself returned.
 *
 * @return the string itself.
 *)
function String_.toString_() : String_;
begin
  toString_ := String_.create(str);
end;

operator := (original: ansiString) s: String_;
begin
  s := String_.create(original);
end;

end.

