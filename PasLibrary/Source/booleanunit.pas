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
      function compareTo(anotherBoolean: Boolean_) : longInt;
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

function Boolean_.compareTo(anotherBoolean: Boolean_) : longInt;
var
  cmp : longInt;
begin
  if (v = true) and (anotherBoolean.v = false) then begin
    cmp := 1;
  end
  else if (v = false) and (anotherBoolean.v = true) then begin
    cmp := -1;
  end
  else begin
    cmp := 0;
  end;

  compareTo := cmp;
end;

function Boolean_.equals(obj: TObject) : boolean;
begin
  if obj = nil then begin
    equals := false;
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
