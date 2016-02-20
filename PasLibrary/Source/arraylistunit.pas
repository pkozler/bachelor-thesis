unit ArrayListUnit;

{$mode objfpc}{$H+}

interface

uses
  StringUnit, Contnrs;

type
  ArrayList = class
    private
      var
        list: TFPObjectList;
    public
      constructor create();
      constructor create(c: ArrayList);
      destructor destroy(); override;
      function getList() : TFPObjectList;
      function add(e: TObject) : boolean;
      procedure add(index: longInt; element: TObject);
      function get(index: longInt) : TObject;
      function set_(index: longInt; element: TObject) : TObject;
      function remove(index: longInt) : TObject;
      function size() : longInt;
      function isEmpty() : boolean;
      procedure clear();
      function toString() : ansiString; override;
      function toString() : String_;
  end;

implementation

uses
  Classes, SysUtils;

constructor ArrayList.create();
begin
  list := TFPObjectList.create;
  list.ownsObjects := false;
end;

constructor ArrayList.create(c: ArrayList);
var
  original: TFPObjectList;
  i: longInt;
begin
  list := TFPObjectList.create;
  list.ownsObjects := false;
  original := c.list;

  for i := 0 to original.count - 1 do begin
    list.add(original.items[i]);
  end;
end;

destructor ArrayList.destroy();
begin
  freeAndNil(list);
  inherited;
end;

function ArrayList.getList() : TFPObjectList;
begin
  getList := list;
end;

function ArrayList.add(e: TObject) : boolean;
begin
  list.add(e);
  add := true;
end;

procedure ArrayList.add(index: longInt; element: TObject);
begin
  list.insert(index, element);
end;

function ArrayList.get(index: longInt) : TObject;
begin
  get := list.items[index];
end;

function ArrayList.set_(index: longInt; element: TObject) : TObject;
var
  original: TObject;
begin
  original := list.items[index];
  list.items[index] := element;
  set_ := original;
end;

function ArrayList.remove(index: longInt) : TObject;
var
  removed: TObject;
begin
  removed := list.items[index];
  list.delete(index);
  remove := removed;
end;

function ArrayList.size() : longInt;
begin
  size := list.count;
end;

function ArrayList.isEmpty() : boolean;
begin
  isEmpty := (list.count = 0);
end;

procedure ArrayList.clear();
begin
  list.clear();
end;

function ArrayList.toString() : ansiString;
var
  s: ansiString;
  len, i: longInt;
begin
  s := '[';
  len := list.count;

  if len > 0 then begin
    s += list.items[0].toString();
  end;

  for i := 1 to len - 1 do begin
    s += ', ' + list.items[i].toString();
  end;

  s += ']';
  toString := s;
end;

function ArrayList.toString() : String_;
begin
  toString := String_.create(ToString());
end;

end.

