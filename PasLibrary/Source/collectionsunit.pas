unit CollectionsUnit;

{$mode objfpc}{$H+}

interface

uses
  SystemUnit, ArrayListUnit;

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
  objectArray: array of TObject;
  l, m, h: longInt;
begin
  objectArray := list.getArray();

  l := 0;
  h := list.size() - 1;
  binarySearch := -1;

  while l <= h do begin
    m := (l + h) div 2;

    if c(objectArray[m], key) > 0 then begin
      h := m - 1;
    end
    else if c(objectArray[m], key) < 0 then begin
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
  destArray, srcArray: array of TObject;
  i: longInt;
begin
  destArray := dest.getArray();
  srcArray := src.getArray();

  for i := 0 to src.size() - 1 do begin
    destArray[i] := srcArray[i];
  end;
end;

class procedure Collections.fill(list: ArrayList; obj: TObject);
var
  objectArray: array of TObject;
  i: longInt;
begin
  objectArray := list.getArray();

  for i := 0 to list.size() - 1 do begin
    objectArray[i] := obj;
  end;
end;

class procedure Collections.sort(list: ArrayList; c: TObjectCompareFunction);
var
  a: array of TObject;
  aux: array of TObject;
begin
  a := list.getArray();
  setLength(aux, list.size());
  _java.mergeSort(a, aux, 0, list.size() - 1, c);
end;

end.

