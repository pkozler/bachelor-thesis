unit StringUnit;

{$mode objfpc}{$H+}

interface

type
  String_ = class
    private
      var str: ansiString;
    public
      constructor create(bytes: array of shortInt);
      constructor create(bytes: array of shortInt; offset: longInt; length: longInt);
      constructor create(original: ansiString);
      destructor destroy(); override;
      function compareTo(anotherString: String_) : longInt;
      function equals(anObject: TObject) : boolean; override;
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
      function toString() : ansiString; override;
  end;

operator := (original: ansiString) s: String_;
operator + (s1: String_; s2: String_) s: String_;

implementation

uses
  SysUtils, StrUtils;

constructor String_.create(bytes: array of shortInt);
begin
  setString(str, @bytes[0], System.length(bytes));
end;

constructor String_.create(bytes: array of shortInt; offset: longInt; length: longInt);
begin
  setString(str, @bytes[offset], length);
end;

constructor String_.create(original: ansiString);
begin
  str := original;
end;

destructor String_.destroy();
begin
  inherited;
end;

function String_.compareTo(anotherString: String_) : longInt;
begin
  compareTo := ansiCompareStr(str, anotherString.str);
end;

function String_.equals(anObject: TObject) : boolean;
begin
  if anObject = nil then begin
    exit(false);
  end;

  if typeOf(self) <> typeOf(anObject) then begin
    exit(false);
  end;

  equals := (ansiCompareStr(self.str, String_(anObject).str) = 0);
end;

function String_.substring(beginIndex: longInt) : String_;
begin
  substring := substring(beginIndex, System.length(str));
end;

function String_.substring(beginIndex: longInt; endIndex: longInt) : String_;
var
  s: String_;
begin
  s.create(copy(str, beginIndex + 1, endIndex - beginIndex));
  substring := s;
end;

function String_.indexOf(ch: longInt) : longInt;
begin
  indexOf := indexOf(ch, 0);
end;

function String_.indexOf(ch: longInt; fromIndex: longInt) : longInt;
var
  substr: ansiString;
begin
  substr := copy(str, fromIndex + 1, System.length(str) - fromIndex);
  indexOf := pos(ansiChar(ch), substr);
end;

function String_.indexOf(s: String_) : longInt;
begin
  indexOf := indexOf(s, 0);
end;

function String_.indexOf(s: String_; fromIndex: longInt) : longInt;
var
  substr: ansiString;
begin
  substr := copy(str, fromIndex + 1, System.length(str) - fromIndex + 1);
  indexOf := pos(s.str, substr);
end;

function String_.length() : longInt;
begin
  length := System.length(str);
end;

function String_.trim() : String_;
var
  s: String_;
begin
  s.create(SysUtils.trim(str));
  trim := s;
end;

function String_.toLowerCase() : String_;
var
  s: String_;
begin
  s.create(lowerCase(str));
  toLowerCase := s;
end;

function String_.toUpperCase() : String_;
var
  s: String_;
begin
  s.create(upperCase(str));
  toUpperCase := s;
end;

function String_.charAt(index: longInt) : ansiChar;
begin
  charAt := str[index];
end;

function String_.replace(oldChar: ansiChar; newChar: ansiChar) : String_;
begin
  replace := replaceStr(str, oldChar, newChar);
end;

function String_.startsWith(prefix: String_) : boolean;
begin
  startsWith := ansiStartsStr(prefix.toString(), str);
end;

function String_.endsWith(suffix: String_) : boolean;
begin
  endsWith := ansiEndsStr(suffix.toString(), str);
end;

function String_.isEmpty() : boolean;
begin
  isEmpty := (self.length() = 0);
end;

function String_.toString() : ansiString;
begin
  toString := str;
end;

operator := (original: ansiString) s: String_;
begin
  s.create(original);
end;

operator + (s1: String_; s2: String_) s: String_;
begin
  s.create(s1.str + s2.str);
end;

end.

