unit ScannerUnit;

{$mode objfpc}{$H+}

interface

uses
  StringUnit;

type
  Scanner = class
    public
      constructor create(source: TObject);
      constructor create();
      destructor destroy(); override;
      function next() : String_;
      function nextBoolean() : boolean;
      function nextByte() : shortInt;
      function nextShort() : smallInt;
      function nextInt() : longInt;
      function nextLong() : int64;
      function nextFloat() : single;
      function nextDouble() : double;
      function nextLine() : String_;
  end;

implementation

uses
  SysUtils;

constructor Scanner.create(source: TObject);
begin
end;

constructor Scanner.create();
begin
end;

destructor Scanner.destroy();
begin
  inherited;
end;

function Scanner.next() : String_;
var
  s: ansiString;
  str: String_;
begin
  read(s);
  str.create(s);
  next := str; // TODO nacist retezec do prvniho bileho znaku
end;

function Scanner.nextBoolean() : boolean;
var
  s: ansiString;
begin
  read(s);
  nextBoolean := strToBool(s);
end;

function Scanner.nextByte() : shortInt;
var
  b: shortInt;
begin
  read(b);
  nextByte := b;
end;

function Scanner.nextShort() : smallInt;
var
  s: smallInt;
begin
  read(s);
  nextShort := s;
end;

function Scanner.nextInt() : longInt;
var
  i: longInt;
begin
  read(i);
  nextInt := i;
end;

function Scanner.nextLong() : int64;
var
  l: int64;
begin
  read(l);
  nextLong := l;
end;

function Scanner.nextFloat() : single;
var
  f: single;
begin
  read(f);
  nextFloat := f;
end;

function Scanner.nextDouble() : double;
var
  d: double;
begin
  read(d);
  nextDouble := d;
end;

function Scanner.nextLine() : String_;
var
  s: ansiString;
  str: String_;
begin
  readLn(s);
  str.create(s);
  nextLine := str;
end;

end.

