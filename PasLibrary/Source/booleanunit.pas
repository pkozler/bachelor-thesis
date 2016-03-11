unit BooleanUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type
  Boolean_ = class
    private
      var
        v : boolean;
    public
      constructor create(value: boolean);
      destructor destroy(); override;
      function booleanValue() : boolean;
      function compareTo(b: Boolean_) : longInt;
      class function compare(x, y: boolean) : longInt;
      function equals(obj: TObject) : boolean; override;
      function toString() : ansiString; override;
      function toString() : String_;
      class function toString(b: boolean) : String_;
      class function parseBoolean(s: String_) : boolean;
  end;

implementation

constructor Boolean_.create(value: boolean);
begin
  v := value;
end;

destructor Boolean_.destroy();
begin
  inherited;
end;

function Boolean_.booleanValue() : boolean;
begin
  booleanValue := v;
end;

function Boolean_.compareTo(b: Boolean_) : longInt;
begin
  compareTo := compare(v, anotherBoolean.v);
end;

class function Boolean_.compare(x, y: boolean) : longInt;
begin
  if x = y then begin
    compare := 0;
  end
  else if x then begin
    compare := 1;
  end
  else begin
    compare := -1;
  end;
end;

function Boolean_.equals(obj: TObject) : boolean;
begin
  if obj = nil then begin
    exit(false);
  end;

  if typeOf(self) <> typeOf(obj) then begin
    exit(false);
  end;

  equals := (v = (Boolean_(obj)).v);
end;

function Boolean_.toString() : ansiString;
var
  s: String_;
begin
  s := toString();
  toString := s.ToString();
end;

function Boolean_.toString() : String_;
begin
  toString := String_.create(BoolToStr(v));
end;

class function Boolean_.toString(b: boolean) : String_;
begin
  toString := String_.create(BoolToStr(b));
end;

class function Boolean_.parseBoolean(s: String_) : boolean;
begin
  parseBoolean := strToBool(s.toString());
end;

end.
