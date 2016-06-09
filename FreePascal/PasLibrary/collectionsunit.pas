unit CollectionsUnit;

{$mode objfpc}{$H+}

interface

uses
  SystemUnit, StringUnit, ArrayListUnit, ListUnit;

  (**
   * This class consists exclusively of static methods that operate on or return collections.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  type
  Collections = class
    public
      class function binarySearch(list: ArrayList; key: Object_) : longInt;
      class function binarySearch(list: ArrayList; key: Object_; c: Comparator) : longInt;
      class procedure copy(dest: List; src: List);
      class procedure fill(list: List; obj: Object_);
      class procedure sort(list: ArrayList);
      class procedure sort(list: ArrayList; c: Comparator);
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
class function Collections.binarySearch(list: ArrayList; key: Object_) : longInt;
begin
  binarySearch := binarySearch(list, key, ObjectComparator.create());
end;

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
class function Collections.binarySearch(list: ArrayList; key: Object_; c: Comparator) : longInt;
var
  objectArray: array of Object_;
  lower, upper, middle : longInt;
  middleValue : Object_;
begin
  objectArray := list.arrProperty;

  lower := 0;
  upper := list.size() - 1;

  while lower <= upper do begin
    middle := lower + ((upper - lower) div 2);
    middleValue := objectArray[middle];

    if c.compare(middleValue, key) < 0 then begin
      lower := middle + 1;
    end
    else if c.compare(middleValue, key) > 0 then begin
      upper := middle - 1;
    end
    else begin
      exit(middle);
    end;
  end;

  binarySearch := -(lower + 1);
end;

(**
 * Copies all of the elements from one list into another.
 *
 * @param dest The destination list.
 * @param src The source list.
 *)
class procedure Collections.copy(dest: List; src: List);
var
  length, i: longInt;
begin
  length := src.size();

  for i := 0 to length - 1 do begin
    dest.set_(i, src.get(i));
  end;
end;

(**
 * Replaces all of the elements of the specified list with the specified
 * element.
 *
 * @param list the list to be filled with the specified element.
 * @param obj The element with which to fill the specified list.
 *)
class procedure Collections.fill(list: List; obj: Object_);
var
  length, i: longInt;
begin
  length := list.size();

  for i := 0 to length - 1 do begin
    list.set_(i, obj);
  end;
end;

(**
 * Sorts the specified list into ascending order, according to the natural
 * ordering of its elements.
 *
 * @param list the list to be sorted.
 *)
class procedure Collections.sort(list: ArrayList);
begin
  sort(list, ObjectComparator.create());
end;

(**
 * Sorts the specified list into ascending order, according to the natural
 * ordering of its elements.
 *
 * @param list the list to be sorted.
 *)
class procedure Collections.sort(list: ArrayList; c: Comparator);
var
  a: array of Object_;
  aux: array of Object_;
begin
  a := list.arrProperty;
  setLength(aux, list.size());
  _java.mergeSort(a, aux, 0, list.size() - 1, c);
end;

end.

