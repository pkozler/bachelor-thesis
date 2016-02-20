unit CollectionsUnit;

{$mode objfpc}{$H+}

interface

uses
  SystemUnit, ArrayListUnit, Contnrs;

  type
  Collections = class
    public
      class function binarySearch(list: ArrayList; key: TObject; c: TObjectCompareFunction) : longInt;
      class procedure copy(dest: ArrayList; src: ArrayList);
      class procedure fill(list: ArrayList; obj: TObject);
      class procedure sort(list: ArrayList; c: TObjectCompareFunction);
  end;

implementation

uses
  SysUtils, Classes;

class function Collections.binarySearch(list: ArrayList; key: TObject; c: TObjectCompareFunction) : longInt;
var
  objectList: TFPObjectList;
  l, m, h: longInt;
begin
  objectList := list.getList();

  l := 0;
  h := objectList.count - 1;
  binarySearch := -1;

  while l <= h do begin
    m := (l + h) div 2;

    if c(objectList.items[m], key) > 0 then begin
      h := m - 1;
    end
    else if c(objectList.items[m], key) < 0 then begin
      l := m + 1;
    end
    else begin
      binarySearch := m;
      break;
    end;
  end;
end;

class procedure Collections.copy(dest: ArrayList; src: ArrayList);
var
  destList, srcList: TFPObjectList;
  i: longInt;
begin
  destList := dest.getList();
  srcList := src.getList();

  for i := 0 to srcList.count - 1 do begin
    destList.items[i] := srcList.items[i];
  end;
end;

class procedure Collections.fill(list: ArrayList; obj: TObject);
var
  objectList: TFPObjectList;
  i: longInt;
begin
  objectList := list.getList();

  for i := 0 to objectList.count - 1 do begin
    objectList.items[i] := obj;
  end;
end;

class procedure Collections.sort(list: ArrayList; c: TObjectCompareFunction);
var
  a: array of TObject;
  aux: array of TObject;
begin
  a := list.getList(); // TODO předělat vnitřní seznam ArrayListu na dynamické pole
  setLength(aux, objectList.count);
  _java.mergeSort(a, aux, 0, objectList.count - 1, c);
end;

end.

