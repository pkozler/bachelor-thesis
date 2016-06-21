unit MathUnit;

{$mode objfpc}{$H+}

interface

uses
  Math, IntegerUnit, LongUnit, FloatUnit, DoubleUnit;

type
  (**
   * The class Math contains methods for performing basic numeric operations such as the elementary exponential,
   * logarithm, square root, and trigonometric functions.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  Math_ = class
    public
      const
          (**
           * The double value that is closer than any other to e, the base of the natural logarithms.
           *)
           E = 2.7182818284590452354;
          (**
           * The double value that is closer than any other to pi, the ratio of the circumference of a circle to its diameter.
           *)
           PI = 3.14159265358979323846;
      class function abs(a: double) : double;
      class function abs(a: single) : single;
      class function abs(a: longInt) : longInt;
      class function abs(a: int64) : int64;
      class function max(a: double; b: double) : double;
      class function max(a: single; b: single) : single;
      class function max(a: longInt; b: longInt) : longInt;
      class function max(a: int64; b: int64) : int64;
      class function min(a: double; b: double) : double;
      class function min(a: single; b: single) : single;
      class function min(a: longInt; b: longInt) : longInt;
      class function min(a: int64; b: int64) : int64;
      class function pow(a: double; b: double) : double;
      class function sqrt(a: double) : double;
      class function log(a: double) : double;
      class function log10(a: double) : double;
      class function sin(a: double) : double;
      class function cos(a: double) : double;
      class function tan(a: double) : double;
      class function asin(a: double) : double;
      class function acos(a: double) : double;
      class function atan(a: double) : double;
      class function round(a: double) : int64;
      class function round(a: single) : longInt;
  end;

implementation

(**
 * Returns the absolute value of a double value.
 *
 * @param a the argument whose absolute value is to be determined
 * @return the absolute value of the argument.
 *)
class function Math_.abs(a: double) : double;
begin
  abs := System.abs(a);
end;

(**
 * Returns the absolute value of a float value.
 *
 * @param a the argument whose absolute value is to be determined
 * @return the absolute value of the argument.
 *)
class function Math_.abs(a: single) : single;
begin
  abs := System.abs(a);
end;

(**
 * Returns the absolute value of an int value.
 *
 * @param a the argument whose absolute value is to be determined
 * @return the absolute value of the argument.
 *)
class function Math_.abs(a: longInt) : longInt;
begin
  abs := System.abs(a);
end;

(**
 * Returns the absolute value of a long value.
 *
 * @param a the argument whose absolute value is to be determined
 * @return the absolute value of the argument.
 *)
class function Math_.abs(a: int64) : int64;
begin
  abs := System.abs(a);
end;

(**
 * Returns the greater of two double values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the larger of a and b.
 *)
class function Math_.max(a: double; b: double) : double;
begin
  max := Math.max(a, b);
end;

(**
 * Returns the greater of two float values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the larger of a and b.
 *)
class function Math_.max(a: single; b: single) : single;
begin
  max := Math.max(a, b);
end;

(**
 * Returns the greater of two int values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the larger of a and b.
 *)
class function Math_.max(a: longInt; b: longInt) : longInt;
begin
  max := Math.max(a, b);
end;

(**
 * Returns the greater of two long values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the larger of a and b.
 *)
class function Math_.max(a: int64; b: int64) : int64;
begin
  max := Math.max(a, b);
end;

(**
 * Returns the smaller of two double values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the smaller of a and b.
 *)
class function Math_.min(a: double; b: double) : double;
begin
  min := Math.min(a, b);
end;

(**
 * Returns the smaller of two float values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the smaller of a and b.
 *)
class function Math_.min(a: single; b: single) : single;
begin
  min := Math.min(a, b);
end;

(**
 * Returns the smaller of two int values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the smaller of a and b.
 *)
class function Math_.min(a: longInt; b: longInt) : longInt;
begin
  min := Math.min(a, b);
end;

(**
 * Returns the smaller of two long values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the smaller of a and b.
 *)
class function Math_.min(a: int64; b: int64) : int64;
begin
  min := Math.min(a, b);
end;

(**
 * Returns the value of the first argument raised to the power of the second
 * argument.
 *
 * @param a the base.
 * @param b the exponent.
 * @return the value a^b.
 *)
class function Math_.pow(a: double; b: double) : double;
begin
  pow := power(a, b);
end;

(**
 * Returns the correctly rounded positive square root of a double value.
 *
 * @param a a value.
 * @return the positive square root of a. If the argument is NaN or less
 * than zero, the result is NaN.
 *)
class function Math_.sqrt(a: double) : double;
begin
  sqrt := System.sqrt(a);
end;

(**
 * Returns the natural logarithm (base e) of a double value.
 *
 * @param a a value
 * @return the value ln a, the natural logarithm of a.
 *)
class function Math_.log(a: double) : double;
begin
  log := ln(a);
end;

(**
 * Returns the base 10 logarithm of a double value.
 *
 * @param a a value
 * @return the base 10 logarithm of a.
 *)
class function Math_.log10(a: double) : double;
begin
  log10 := Math.log10(a);
end;

(**
 * Returns the trigonometric sine of an angle.
 *
 * @param a an angle, in radians.
 * @return the sine of the argument.
 *)
class function Math_.sin(a: double) : double;
begin
  sin := System.sin(a);
end;

(**
 * Returns the trigonometric cosine of an angle.
 *
 * @param a an angle, in radians.
 * @return the cosine of the argument.
 *)
class function Math_.cos(a: double) : double;
begin
  cos := System.cos(a);
end;

(**
 * Returns the trigonometric tangent of an angle.
 *
 * @param a an angle, in radians.
 * @return the tangent of the argument.
 *)
class function Math_.tan(a: double) : double;
begin
  tan := Math.tan(a);
end;

(**
 * Returns the arc sine of a value; the returned angle is in the range -pi/2
 * through pi/2.
 *
 * @param a the value whose arc sine is to be returned.
 * @return the arc sine of the argument.
 *)
class function Math_.asin(a: double) : double;
begin
  asin := arcsin(a);
end;

(**
 * Returns the arc cosine of a value; the returned angle is in the range 0.0
 * through pi.
 *
 * @param a the value whose arc cosine is to be returned.
 * @return the arc cosine of the argument.
 *)
class function Math_.acos(a: double) : double;
begin
  acos := arccos(a);
end;

(**
 * Returns the arc tangent of a value; the returned angle is in the range
 * -pi/2 through pi/2.
 *
 * @param a the value whose arc tangent is to be returned.
 * @return the arc tangent of the argument.
 *)
class function Math_.atan(a: double) : double;
begin
  atan := arctan(a);
end;

(**
 * Returns the closest long to the argument, with ties rounding up.
 *
 * @param a a floating-point value to be rounded to a long.
 * @return the value of the argument rounded to the nearest long value.
 *)
class function Math_.round(a: double) : int64;
begin
  // if NaN, the result is 0
  if Double_.compare(a, Double_.NaN) = 0 then begin
    exit(0);
  end;

  // if less than / equal to the corresponding integer type minimal value, the result is equal to that value
  if (Double_.compare(a, Double_.NEGATIVE_INFINITY) = 0)
  and (a <= Long.MIN_VALUE) then begin
    exit(Long.MIN_VALUE);
  end;

  // if greater than / equal to the corresponding integer type maximal value, the result is equal to that value
  if (Double_.compare(a, Double_.POSITIVE_INFINITY) = 0)
  and (a >= Long.MAX_VALUE) then begin
    exit(Long.MAX_VALUE);
  end;

  // rounding towards zero for negative values
  if (a < 0) and (frac(a) <= 0.5) then begin
    exit(trunc(a));
  end;

  // rounding away from zero for positive values
  if (a > 0) and (frac(a) >= 0.5) then begin
    exit(trunc(a) + 1);
  end;

  round := int64(System.round(a));
end;

(**
 * Returns the closest int to the argument, with ties rounding up.
 *
 * @param a a floating-point value to be rounded to an integer.
 * @return the value of the argument rounded to the nearest int value.
 *)
class function Math_.round(a: single) : longInt;
begin
  // if NaN, the result is 0
  if Float.compare(a, Float.NaN) = 0 then begin
    exit(0);
  end;

  // if less than / equal to the corresponding integer type minimal value, the result is equal to that value
  if (Float.compare(a, Float.NEGATIVE_INFINITY) = 0)
  and (a <= Integer_.MIN_VALUE) then begin
    exit(Integer_.MIN_VALUE);
  end;

  // if greater than / equal to the corresponding integer type maximal value, the result is equal to that value
  if (Float.compare(a, Float.POSITIVE_INFINITY) = 0)
  and (a >= Integer_.MAX_VALUE) then begin
    exit(Integer_.MAX_VALUE);
  end;

  // rounding towards zero for negative values
  if (a < 0) and (frac(a) <= 0.5) then begin
    exit(trunc(a));
  end;

  // rounding away from zero for positive values
  if (a > 0) and (frac(a) >= 0.5) then begin
    exit(trunc(a) + 1);
  end;

  round := longInt(System.round(a));
end;

end.

