unit StringBuilderUint;

{$mode objfpc}{$H+}

interface

uses
  Classes, StringUnit;

type
  StringBuilder = class
    private
      const
        DEFAULT_CAPACITY = 16;
        RESIZE_COEF = 2;
      var
        buffer: ^ansiChar;
        count, capacity: longInt;
    public
      constructor create();
      destructor destroy(); override;
      function append(str: String_) : StringBuilder;
      function toString() : ansiString; override;
      function toString() : String_;
  end;

implementation

uses
  SysUtils;

constructor StringBuilder.create();
begin
  count := 0;
  capacity := DEFAULT_CAPACITY;
  buffer := getMem(capacity);
  buffer[0] := #0;
end;

destructor StringBuilder.destroy();
begin
  inherited;
end;

function StringBuilder.append(str: String_) : StringBuilder;
var
  cStr: ^ansiChar;
  len: longInt;
begin
  len := str.length();
  cStr := getMem(len + 1);
  strPCopy(cStr, str.toString());

  if count + len >= capacity then begin
    capacity := count + len * RESIZE_COEF;
    buffer := reAllocMem(buffer, capacity);
  end;

  strcat(buffer, cStr);
  count := count + len;
  append := self;
end;

function StringBuilder.toString() : ansiString;
begin
  toString := strPas(buffer);
end;

function StringBuilder.toString() : String_;
begin
  toString := String_.create(buffer);
end;

end.

