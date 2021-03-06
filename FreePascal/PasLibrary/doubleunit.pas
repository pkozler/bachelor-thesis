unit DoubleUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type

  (*
      DoubleInt64 variant record provides the ability to set the Double value
      and get the Int64 value with the same binary representation.
  *)
  DoubleToInt64 = record
    case binary: boolean of
      false: (val: double);
      true: (bits: int64);
  end;

  (**
   * The Double class wraps a value of the primitive type double in an object.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  Double_ = class(Comparable)
    private
      var
        // an inner value
        v: double;
      class function getNegativeZeroBits() : int64;
    public
      const
          (**
           * A constant holding the positive infinity of type double.
           *)
           POSITIVE_INFINITY = 1.0 / 0.0;
          (**
           * A constant holding the negative infinity of type double.
           *)
           NEGATIVE_INFINITY = -1.0 / 0.0;
          (**
           * A constant holding a Not-a-Number (NaN) value of type double.
           *)
           NaN = 0.0 / 0.0;
          (**
           * A constant holding the largest positive finite value of type double, (2-2^-52)·2^1023.
           *)
           MAX_VALUE = 1.7976931348623157e+308;
          (**
           * A constant holding the smallest positive nonzero value of type double, 2^-1074.
           *)
           MIN_VALUE = 4.9e-324;
          (**
           * Maximum exponent a finite double variable may have.
           *)
           MAX_EXPONENT = 1023;
          (**
           * Minimum exponent a normalized double variable may have.
           *)
           MIN_EXPONENT = -1022;
          (**
           * A constant holding the smallest positive normal value of type double, 2^-1022.
           *)
           MIN_NORMAL = 2.2250738585072014e-308;
      constructor create(value: double);
      function doubleValue() : double;
      function compareTo(anotherDouble: Object_) : longInt; override;
      class function compare(d1, d2: double) : longInt;
      function equals_(obj: Object_) : boolean; override;
      function toString_() : String_; override;
      class function toString_(d: double) : String_;
      class function parseDouble(s: String_) : double;
  end;

implementation

uses
  Math;

(**
 * Constructs a newly allocated Double object that represents the primitive
 * double argument.
 *
 * @param value the value to be represented by the Double.
 *)
constructor Double_.create(value: double);
begin
  v := value;
end;

(*
    returns the "binary representation" of negative zero value for comparison purposes
*)
class function Double_.getNegativeZeroBits(): int64;
var
  bitConverter : DoubleToInt64;
begin
  bitConverter.val := -0.0;
  getNegativeZeroBits := bitConverter.bits;
end;

(**
 * Returns the double value of this Double object.
 *
 * @return the double value represented by this object
 *)
function Double_.doubleValue() : double;
begin
  doubleValue := v;
end;

(**
 * Compares two Double objects numerically.
 *
 * @param anotherDouble the Double to be compared.
 * @return the value 0 if anotherDouble is numerically equal to this Double;
 * a value less than 0 if this Double is numerically less than
 * anotherDouble; and a value greater than 0 if this Double is numerically
 * greater than anotherDouble.
 *)
function Double_.compareTo(anotherDouble: Object_) : longInt;
begin
  compareTo := compare(v, (anotherDouble as Double_).v);
end;

(**
 * Compares the two specified double values.
 *
 * @param d1 the first double to compare
 * @param d2 the second double to compare
 * @return the value 0 if d1 is numerically equal to d2; a value less than 0
 * if d1 is numerically less than d2; and a value greater than 0 if d1 is
 * numerically greater than d2.
 *)
class function Double_.compare(d1, d2: double) : longInt;
var
  vBits, v2Bits : DoubleToInt64;
  negativeZeroBits : int64;
begin
  (* testing for NaN values (a NaN value is considered greated
       than any other, including positive infinity,
       and two NaN values are considered equal) *)
  if isNan(d1) then begin
    if isNan(d2) then begin
       exit(0);
    end;

    exit(1);
  end;

  if isNan(d2) then begin
    exit(-1);
  end;

  vBits.val := d1;
  v2Bits.val := d2;
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
  if d1 > d2 then begin
    compare := 1;
  end
  else if d1 < d2 then begin
    compare := -1;
  end
  else begin
    compare := 0;
  end;
end;

(**
 * Compares this object against the specified object.
 *
 * @param obj the object to compare with.
 * @return true if the objects are the same; false otherwise.
 *)
function Double_.equals_(obj: Object_) : boolean;
var
  vBits, v2Bits : DoubleToInt64;
  v2 : double;
  negativeZeroBits : int64;
begin
  // testing another object reference for a NULL value
  if obj = nil then begin
    exit(false);
  end;

  // testing object class equality
  if typeOf(self) <> typeOf(obj) then begin
    exit(false);
  end;

  v2 := (obj as Double_).v;

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
 * Returns a string representation of this Double object.
 *
 * @return a String representation of this object.
 *)
function Double_.toString_() : String_;
begin
  toString_ := Double_.toString_(v);
end;

(**
 * Returns a string representation of the double argument.
 *
 * @param d the double to be converted.
 * @return a string representation of the argument.
 *)
class function Double_.toString_(d: double) : String_;
var
  fs: TFormatSettings;
begin
  fs.DecimalSeparator := '.';
  toString_ := String_.create(FloatToStr(d, fs));
end;

(**
 * Returns a new double initialized to the value represented by the
 * specified String, as performed by the valueOf method of class Double.
 *
 * @param s the string to be parsed.
 * @return the double value represented by the string argument.
 *)
class function Double_.parseDouble(s: String_) : double;
var
  fs: TFormatSettings;
  str, sign: String_;
  value: double;
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
  parseDouble := value;
end;

operator := (original: double) s: Double_;
begin
  s.create(original);
end;

end.

