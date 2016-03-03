unit IntegerUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type
  Integer_ = class
    private
      var
        v: longInt;
    public
      const
           MAX_VALUE = 2147483647;
           MIN_VALUE = -2147483648;
      constructor create(value: longInt);
      destructor destroy(); override;
      function intValue() : longInt;
      function compareTo(anotherInteger: Integer_) : longInt;
      class function compare(x, y: longInt) : longInt;
      function equals(obj: TObject) : boolean; override;
      function toString() : ansiString; override;
      function toString() : String_;
      class function toString(i: longInt) : String_;
      class function parseInt(s: String_) : longInt;
  end;

implementation

constructor Integer_.create(value: longInt);
begin
  v := value;
end;

destructor Integer_.destroy();
begin
  inherited;
end;

function Integer_.intValue() : longInt;
begin
  intValue := v;
end;

function Integer_.compareTo(anotherInteger: Integer_) : longInt;
begin
  compareTo := compare(v, anotherInteger.v);
end;

class function Integer_.compare(x, y: longInt) : longInt;
begin
  if x < y then begin
     compare := -1;
  end
  else if x = y then begin
     compare := 0;
  end
  else begin
    compare := 1;
  end;
end;

function Integer_.equals(obj: TObject) : boolean;
begin
  if obj = nil then begin
    exit(false);
  end;

  if typeOf(self) <> typeOf(obj) then begin
    exit(false);
  end;

  equals := (v = (Integer_(obj)).v);
end;

function Integer_.toString() : ansiString;
var
  s: String_;
begin
  s := toString();
  toString := s.ToString();
end;

function Integer_.toString() : String_;
begin
  toString := Integer_.toString(v);
end;

class function Integer_.toString(i: longInt) : String_;
begin
  toString := String_.create(IntToStr(i));
end;

class function Integer_.parseInt(s: String_) : longInt;
begin
  parseInt := strToInt(s.toString());
end;

end.

