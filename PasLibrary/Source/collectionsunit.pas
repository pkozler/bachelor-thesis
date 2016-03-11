unit CollectionsUnit;

{$mode objfpc}{$H+}

interface

uses
  SystemUnit, ArrayListUnit;

  (**
   * This class consists exclusively of static methods that operate on or return collections.
   *
   * @author Petr Kozler (A13B0359P)
   *)
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

(**
 * Searches the specified list for the specified object using the binary
 * search algorithm.
 *
 * @param list the list to be searched.
 * @param key the key to be searched for.
 * @return the index of the search key, if it is contained in the list;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as
 * the point at which the key would be inserted into the list: the index of
 * the first element greater than the key, or list.size() if all elements in
 * the list are less than the specified key. Note that this guarantees that
 * the return value will be >= 0 if and only if the key is found.
 *)
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

(**
 * Copies all of the elements from one list into another.
 *
 * @param dest The destination list.
 * @param src The source list.
 *)
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

(**
 * Replaces all of the elements of the specified list with the specified
 * element.
 *
 * @param list the list to be filled with the specified element.
 * @param obj The element with which to fill the specified list.
 *)
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

(**
 * Sorts the specified list into ascending order, according to the natural
 * ordering of its elements.
 *
 * @param list the list to be sorted.
 *)
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

