unit TestObjectComparatorUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, StringUnit, TestObjectUnit;

type
  (**
   * The {@code TestObjectComparator} class represents a comparator
   * for the {@code TestObject} class instances.
   *
   * @author Petr Kozler
   *)
  TestObjectComparator = class(Comparator)
    function compare(o1, o2: Object_): longInt; override;
  end;

implementation

function TestObjectComparator.compare(o1, o2: Object_): longInt;
begin
  (**
   * Compares its two arguments for order.
   *
   * @param o1 first object
   * @param o2 second object
   * @return comparison result
   *)
  compare := (o1 as TestObject).getI() - (o2 as TestObject).getI();
end;

end.

