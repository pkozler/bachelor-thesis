unit MathUnit;

{$mode objfpc}{$H+}

interface

uses
  Math;

type
  Math_ = class
    public
      const
           E = 2.7182818284590452354;
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

class function Math_.abs(a: double) : double;
begin
  abs := abs(a);
end;

class function Math_.abs(a: single) : single;
begin
  abs := abs(a);
end;

class function Math_.abs(a: longInt) : longInt;
begin
  abs := abs(a);
end;

class function Math_.abs(a: int64) : int64;
begin
  abs := abs(a);
end;

class function Math_.max(a: double; b: double) : double;
begin
  max := max(a, b);
end;

class function Math_.max(a: single; b: single) : single;
begin
  max := max(a, b);
end;

class function Math_.max(a: longInt; b: longInt) : longInt;
begin
  max := max(a, b);
end;

class function Math_.max(a: int64; b: int64) : int64;
begin
  max := max(a, b);
end;

class function Math_.min(a: double; b: double) : double;
begin
  min := min(a, b);
end;

class function Math_.min(a: single; b: single) : single;
begin
  min := min(a, b);
end;

class function Math_.min(a: longInt; b: longInt) : longInt;
begin
  min := min(a, b);
end;

class function Math_.min(a: int64; b: int64) : int64;
begin
  min := min(a, b);
end;

class function Math_.pow(a: double; b: double) : double;
begin
  pow := power(a, b);
end;

class function Math_.sqrt(a: double) : double;
begin
  sqrt := sqrt(a);
end;

class function Math_.log(a: double) : double;
begin
  log := ln(a);
end;

class function Math_.log10(a: double) : double;
begin
  log10 := log10(a);
end;

class function Math_.sin(a: double) : double;
begin
  sin := sin(a);
end;

class function Math_.cos(a: double) : double;
begin
  cos := cos(a);
end;

class function Math_.tan(a: double) : double;
begin
  tan := tan(a);
end;

class function Math_.asin(a: double) : double;
begin
  asin := arcsin(a);
end;

class function Math_.acos(a: double) : double;
begin
  acos := arccos(a);
end;

class function Math_.atan(a: double) : double;
begin
  atan := arctan(a);
end;

class function Math_.round(a: double) : int64;
begin
  round := int64(round(a));
end;

class function Math_.round(a: single) : longInt;
begin
  round := longInt(round(a));
end;

end.

