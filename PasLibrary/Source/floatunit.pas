unit FloatUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type
  FloatToInt32 = record
    case binary: boolean of
      false: (val: single);
      true: (bits: longInt);
  end;

  Float = class
    private
      var
        v: single;
      class function getNegativeZeroBits() : longInt;
    public
      const
           POSITIVE_INFINITY = 1.0 / 0.0;
           NEGATIVE_INFINITY = -1.0 / 0.0;
           NaN = 0.0 / 0.0;
           MAX_VALUE = 3.4028235e+38;
           MIN_VALUE = 1.4e-45;
           MAX_EXPONENT = 127;
           MIN_EXPONENT = -126;
           MIN_NORMAL = 1.17549435e-38;
      constructor create(value: single);
      destructor destroy(); override;
      function floatValue() : single;
      function compareTo(anotherFloat: Float) : longInt;
      class function compare(f1, f2: single) : longInt;
      function equals(obj: TObject) : boolean; override;
      function toString() : ansiString; override;
      function toString() : String_;
      class function toString(f: single) : String_;
      class function parseFloat(s: String_) : single;
  end;

implementation

uses
  Math;

constructor Float.create(value: single);
begin
  v := value;
end;

destructor Float.destroy();
begin
  inherited;
end;

class function Float.getNegativeZeroBits(): longInt;
var
  bitConverter : FloatToInt32;
begin
  bitConverter.val := -0.0;
  getNegativeZeroBits := bitConverter.bits;
end;

function Float.floatValue() : single;
begin
  floatValue := v;
end;

function Float.compareTo(anotherFloat: Float) : longInt;
begin
  compareTo := compare(v, anotherFloat.v);
end;

class function Float.compare(f1, f2: single) : longInt;
var
  vBits, v2Bits : FloatToInt32;
  negativeZeroBits : longInt;
begin
  if isNan(f1) then begin
    if isNan(f2) then begin
       exit(0);
    end;

    exit(1);
  end;

  if isNan(f2) then begin
    exit(-1);
  end;

  vBits.val := f1;
  v2Bits.val := f2;
  negativeZeroBits := getNegativeZeroBits();

  if (vBits.bits = 0) and (v2Bits.bits = negativeZeroBits) then begin
    exit(1);
  end;

  if (vBits.bits = negativeZeroBits) and (v2Bits.bits = 0) then begin
    exit(-1);
  end;

  if f1 > f2 then begin
    compare := 1;
  end
  else if f1 < f2 then begin
    compare := -1;
  end
  else begin
    compare := 0;
  end;
end;

function Float.equals(obj: TObject) : boolean;
var
  vBits, v2Bits : FloatToInt32;
  v2 : single;
  negativeZeroBits : longInt;
begin
  if obj = nil then begin
    exit(false);
  end;

  if typeOf(self) <> typeOf(obj) then begin
    exit(false);
  end;

  v2 := Float(obj).v;

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

function Float.toString() : ansiString;
var
  s: String_;
begin
  s := toString();
  toString := s.ToString();
end;

function Float.toString() : String_;
begin
  toString := Float.toString(v);
end;

class function Float.toString(f: single) : String_;
begin
  toString := String_.create(FloatToStr(f));
end;

class function Float.parseFloat(s: String_) : single;
begin
  parseFloat := strToFloat(s.toString());
end;

end.

