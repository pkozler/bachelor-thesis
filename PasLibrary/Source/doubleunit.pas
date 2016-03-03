unit DoubleUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type
  DoubleToInt64 = record
    case binary: boolean of
      false: (val: double);
      true: (bits: int64);
  end;

  Double_ = class
    private
      var
        v: double;
      class function getNegativeZeroBits() : int64;
    public
      const
           POSITIVE_INFINITY = 1.0 / 0.0;
           NEGATIVE_INFINITY = -1.0 / 0.0;
           NaN = 0.0 / 0.0;
           MAX_VALUE = 1.7976931348623157e+308;
           MIN_VALUE = 4.9e-324;
           MAX_EXPONENT = 1023;
           MIN_EXPONENT = -1022;
           MIN_NORMAL = 2.2250738585072014e-308;
      constructor create(value: double);
      destructor destroy(); override;
      function doubleValue() : double;
      function compareTo(anotherDouble: Double_) : longInt;
      class function compare(val, val2: double) : longInt;
      function equals(obj: TObject) : boolean; override;
      function toString() : ansiString; override;
      function toString() : String_;
      class function toString(d: double) : String_;
      class function parseDouble(s: String_) : double;
  end;

implementation

uses
  Math;

constructor Double_.create(value: double);
begin
  v := value;
end;

destructor Double_.destroy();
begin
  inherited;
end;

class function Double_.getNegativeZeroBits(): int64;
var
  bitConverter : DoubleToInt64;
begin
  bitConverter.val := -0.0;
  getNegativeZeroBits := bitConverter.bits;
end;

function Double_.doubleValue() : double;
begin
  doubleValue := v;
end;

function Double_.compareTo(anotherDouble: Double_) : longInt;
begin
  compareTo := compare(v, anotherDouble.v);
end;

class function Double_.compare(val, val2: double) : longInt;
var
  vBits, v2Bits : DoubleToInt64;
  negativeZeroBits : int64;
begin
  if isNan(val) then begin
    if isNan(val2) then begin
       exit(0);
    end;

    exit(1);
  end;

  if isNan(val2) then begin
    exit(-1);
  end;

  vBits.val := val;
  v2Bits.val := val2;
  negativeZeroBits := getNegativeZeroBits();

  if (vBits.bits = 0) and (v2Bits.bits = negativeZeroBits) then begin
    exit(1);
  end;

  if (vBits.bits = negativeZeroBits) and (v2Bits.bits = 0) then begin
    exit(-1);
  end;

  if val > val2 then begin
    compare := 1;
  end
  else if val < val2 then begin
    compare := -1;
  end
  else begin
    compare := 0;
  end;
end;

function Double_.equals(obj: TObject) : boolean;
var
  vBits, v2Bits : DoubleToInt64;
  v2 : double;
  negativeZeroBits : int64;
begin
  if obj = nil then begin
    exit(false);
  end;

  if typeOf(self) <> typeOf(obj) then begin
    exit(false);
  end;

  v2 := Double_(obj).v;

  if isNan(v) and isNan(v2) then begin
    exit(true);
  end;

  vBits.val := v;
  v2Bits.val := v2;
  negativeZeroBits := getNegativeZeroBits();

  if vBits.bits = negativeZeroBits then begin
    exit(v2Bits.bits = negativeZeroBits);
  end;

  if v2Bits.bits = negativeZeroBits then begin
    exit(vBits.bits = negativeZeroBits);
  end;

  equals := (v = v2);
end;

function Double_.toString() : ansiString;
var
  s: String_;
begin
  s := toString();
  toString := s.ToString();
end;

function Double_.toString() : String_;
begin
  toString := Double_.toString(v);
end;

class function Double_.toString(d: double) : String_;
begin
  toString := String_.create(FloatToStr(d));
end;

class function Double_.parseDouble(s: String_) : double;
begin
  parseDouble := strToFloat(s.toString());
end;

end.

