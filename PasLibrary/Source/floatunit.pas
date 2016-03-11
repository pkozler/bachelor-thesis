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

  (**
   * The Float class wraps a value of primitive type float in an object.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  Float = class
    private
      var
        v: single;
      class function getNegativeZeroBits() : longInt;
    public
      const
          (**
           * A constant holding the positive infinity of type float.
           *)
           POSITIVE_INFINITY = 1.0 / 0.0;
          (**
           * A constant holding the negative infinity of type float.
           *)
           NEGATIVE_INFINITY = -1.0 / 0.0;
          (**
           * A constant holding a Not-a-Number (NaN) value of type float.
           *)
           NaN = 0.0 / 0.0;
          (**
           * A constant holding the largest positive finite value of type float, (2-2^-23)·2^127.
           *)
           MAX_VALUE = 3.4028235e+38;
          (**
           * A constant holding the smallest positive nonzero value of type float, 2-^149.
           *)
           MIN_VALUE = 1.4e-45;
          (**
           * Maximum exponent a finite float variable may hav
           *)
           MAX_EXPONENT = 127;
          (**
           * Minimum exponent a normalized float variable may have.
           *)
           MIN_EXPONENT = -126;
          (**
           * A constant holding the smallest positive normal value of type float, 2^-126.
           *)
           MIN_NORMAL = 1.17549435e-38;
      constructor create(value: single);
      destructor destroy(); override;
      function floatValue() : single;
      function compareTo(anotherFloat: Float) : longInt;
      class function compare(f1, f2: single) : longInt;
      function equals(obj: TObject) : boolean; override;
      function toString() : String_;
      class function toString(f: single) : String_;
      class function parseFloat(s: String_) : single;
      function toString() : ansiString; override;
  end;

implementation

uses
  Math;

(**
 * Constructs a newly allocated Float object that represents the primitive
 * float argument.
 *
 * @param value the value to be represented by the Float.
 *)
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

(**
 * Returns the float value of this Float object.
 *
 * @return the float value represented by this object
 *)
function Float.floatValue() : single;
begin
  floatValue := v;
end;

(**
 * Compares two Float objects numerically.
 *
 * @param anotherFloat the Float to be compared.
 * @return the value 0 if anotherFloat is numerically equal to this Float; a
 * value less than 0 if this Float is numerically less than anotherFloat;
 * and a value greater than 0 if this Float is numerically greater than
 * anotherFloat.
 *)
function Float.compareTo(anotherFloat: Float) : longInt;
begin
  compareTo := compare(v, anotherFloat.v);
end;

(**
 * Compares the two specified float values.
 *
 * @param f1 the first float to compare.
 * @param f2 the second float to compare.
 * @return the value 0 if f1 is numerically equal to f2; a value less than 0
 * if f1 is numerically less than f2; and a value greater than 0 if f1 is
 * numerically greater than f2.
 *)
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

(**
 * Compares this object against the specified object.
 *
 * @param obj the object to be compared
 * @return true if the objects are the same; false otherwise.
 *)
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

(**
 * Returns a string representation of this Float object.
 *
 * @return a String representation of this object.
 *)
function Float.toString() : String_;
begin
  toString := Float.toString(v);
end;

(**
 * Returns a string representation of the float argument.
 *
 * @param f the float to be converted.
 * @return a string representation of the argument.
 *)
class function Float.toString(f: single) : String_;
begin
  toString := String_.create(FloatToStr(f));
end;

(**
 * Returns a new float initialized to the value represented by the specified
 * String, as performed by the valueOf method of class Float.
 *
 * @param s the string to be parsed.
 * @return the float value represented by the string argument.
 *)
class function Float.parseFloat(s: String_) : single;
begin
  parseFloat := strToFloat(s.toString());
end;

function Float.toString() : ansiString;
var
  s: String_;
begin
  s := toString();
  toString := s.ToString();
end;

end.

