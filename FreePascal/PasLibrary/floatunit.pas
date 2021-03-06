unit FloatUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type
  (*
      FloatToInt32 variant record provides the ability to set the Single value
      and get the LongInt value with the same binary representation.
  *)
  FloatToInt32 = record
    case binary: boolean of
      false: (val: single);
      true: (bits: longInt);
  end;

  (**
   * The Float class wraps a value of primitive type single (representing a float value) in an object.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  Float = class(Comparable)
    private
      var
        // an inner value
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
      function floatValue() : single;
      function compareTo(anotherFloat: Object_) : longInt; override;
      class function compare(f1, f2: single) : longInt;
      function equals_(obj: Object_) : boolean; override;
      function toString_() : String_; override;
      class function toString_(f: single) : String_;
      class function parseFloat(s: String_) : single;
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

(*
    returns the "binary representation" of negative zero value for comparison purposes
*)
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
function Float.compareTo(anotherFloat: Object_) : longInt;
begin
  compareTo := compare(v, (anotherFloat as Float).v);
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
  (* testing for NaN values (a NaN value is considered greated
       than any other, including positive infinity,
       and two NaN values are considered equal) *)
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

  (* testing for +0.0 and -0.0 value (a positive zero
       is considered greater than a negative zero) *)
  if (vBits.bits = 0) and (v2Bits.bits = negativeZeroBits) then begin
    exit(1);
  end;

  if (vBits.bits = negativeZeroBits) and (v2Bits.bits = 0) then begin
    exit(-1);
  end;

  (* testing for other values and returning
       1 if first value is greater, 0 if first value
       equals second value, -1 otherwise *)
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
function Float.equals_(obj: Object_) : boolean;
var
  vBits, v2Bits : FloatToInt32;
  v2 : single;
  negativeZeroBits : longInt;
begin
  // testing another object reference for a NULL value
  if obj = nil then begin
    exit(false);
  end;

  // testing object class equality
  if typeOf(self) <> typeOf(obj) then begin
    exit(false);
  end;

  v2 := (obj as Float).v;

  // testing for NaN values (two NaN values are considered equal)
  if isNan(v) and isNan(v2) then begin
    exit(true);
  end;

  vBits.val := v;
  v2Bits.val := v2;
  negativeZeroBits := getNegativeZeroBits();

  // testing for zero values (+0.0 is considered greater than -0.0)
  if vBits.bits = negativeZeroBits then begin
    exit(v2Bits.bits = negativeZeroBits);
  end;

  if v2Bits.bits = negativeZeroBits then begin
    exit(vBits.bits = negativeZeroBits);
  end;

  // testing other values
  equals_ := v = v2;
end;

(**
 * Returns a string representation of this Float object.
 *
 * @return a String representation of this object.
 *)
function Float.toString_() : String_;
begin
  toString_ := Float.toString_(v);
end;

(**
 * Returns a string representation of the float argument.
 *
 * @param f the float to be converted.
 * @return a string representation of the argument.
 *)
class function Float.toString_(f: single) : String_;
var
  fs: TFormatSettings;
begin
  fs.DecimalSeparator := '.';
  toString_ := String_.create(FloatToStr(f, fs));
end;

(**
 * Returns a new float initialized to the value represented by the specified
 * String, as performed by the valueOf method of class Float.
 *
 * @param s the string to be parsed.
 * @return the float value represented by the string argument.
 *)
class function Float.parseFloat(s: String_) : single;
var
  fs: TFormatSettings;
  str, sign: String_;
  value: single;
begin
  // parsing with dot as a decimal separator
  fs.DecimalSeparator := '.';
  str := s.trim();
  value := strToFloat(str.strProperty, fs);
  sign := String_.create('-');

  // negative zero handling
  if (value = 0) and s.startsWith(sign) then begin
    value := -0.0;
  end;

  freeAndNil(str);
  freeAndNil(sign);
  parseFloat := value;
end;

operator := (original: single) s: Float;
begin
  s.create(original);
end;

end.

