unit LinkedListUnit;

{$mode objfpc}{$H+}

interface

uses
  StringUnit, ListUnit;

type
  LinkedListNode = class
    private
      var
        next: LinkedListNode;
        previous: LinkedListNode;
        value: Object_;
  end;

  (**
   * Doubly-linked list implementation of the List abstract class.
   *
   * @param E the type of elements held in this collection
   * @author Petr Kozler (A13B0359P)
   *)
  LinkedList = class(List)
    private
      var
        count: longInt;
        first: LinkedListNode;
        last: LinkedListNode;
      procedure addAfter(node, newNode: LinkedListNode);
      procedure addBefore(node, newNode: LinkedListNode);
      procedure addFirst(newNode: LinkedListNode);
      procedure addLast(newNode: LinkedListNode);
      procedure removeNode(node: LinkedListNode);
    public
      constructor create();
      constructor create(c: LinkedList);
      destructor destroy(); override;
      function add(e: Object_) : boolean; override;
      procedure add(index: longInt; element: Object_); override;
      function get(index: longInt) : Object_; override;
      function set_(index: longInt; element: Object_) : Object_; override;
      function remove(index: longInt) : Object_; override;
      function size() : longInt; override;
      procedure clear(); override;
      function toString_() : String_; override;
  end;

implementation

uses
  StringBuilderUnit, Classes, SysUtils;

(**
 * Constructs an empty list.
 *)
constructor LinkedList.create();
begin
  count := 0;
  first := nil;
  last := nil;
end;

(**
 * Constructs a list containing the elements of the specified collection, in
 * the order they are returned by the collection's iterator.
 *
 * @param c the collection whose elements are to be placed into this list
 *)
constructor LinkedList.create(c: LinkedList);
var
  node: LinkedListNode;
begin
  create();
  node := c.first;

  while node <> nil do begin
    add(node.value);
    node := node.next;
  end;
end;

destructor LinkedList.destroy();
begin
  clear();
  inherited;
end;

procedure LinkedList.addAfter(node, newNode: LinkedListNode);
begin
  newNode.previous := node;
  newNode.next := node.next;

  if node.next = nil then begin
    last := newNode;
  end
  else begin
    node.next.previous := newNode;
  end;

  node.next := newNode;
end;

procedure LinkedList.addBefore(node, newNode: LinkedListNode);
begin
  newNode.previous := node.previous;
  newNode.next := node;

  if node.previous = nil then begin
    first := newNode;
  end
  else begin
    node.previous.next := newNode;
  end;

  node.previous := newNode;
end;

procedure LinkedList.addFirst(newNode: LinkedListNode);
begin
  if first = nil then begin
    first := newNode;
    last := newNode;
    newNode.previous := nil;
    newNode.next := nil;
  end
  else begin
    addBefore(first, newNode);
  end;
end;

procedure LinkedList.addLast(newNode: LinkedListNode);
begin
  if last = nil then begin
    addFirst(newNode);
  end
  else begin
    addAfter(last, newNode);
  end;
end;

procedure LinkedList.removeNode(node: LinkedListNode);
begin
  if node.previous = nil then begin
    first := node.next;
  end
  else begin
    node.previous.next := node.next;
  end;

  if node.next = nil then begin
    last := node.previous;
  end
  else begin
    node.next.previous := node.previous;
  end;
end;

(**
 * Appends the specified element to the end of this list.
 *
 * @param e element to be appended to this list
 * @return true
 *)
function LinkedList.add(e: Object_) : boolean;
var
  newNode: LinkedListNode;
begin
  newNode := LinkedListNode.create();
  newNode.value := e;
  addLast(newNode);
  inc(count);
  add := true;
end;

(**
 * Inserts the specified element at the specified position in this list.
 *
 * @param index index at which the specified element is to be inserted
 * @param element element to be inserted
 *)
procedure LinkedList.add(index: longInt; element: Object_);
var
  node, newNode: LinkedListNode;
  i: longInt;
begin
  newNode := LinkedListNode.create();
  newNode.value := element;

  if count < 1 then begin
    addFirst(newNode);
  end
  else begin
    node := first;

    if index < 1 then begin
      addBefore(node, newNode);
    end
    else begin

      for i := 1 to index - 1 do begin
        node := node.next;
      end;

      addAfter(node, newNode);
    end;
  end;

  inc(count);
end;

(**
 * Returns the element at the specified position in this list.
 *
 * @param index index of the element to return
 * @return the element at the specified position in this list
 *)
function LinkedList.get(index: longInt) : Object_;
var
  node: LinkedListNode;
  i: longInt;
begin
  node := first;

  for i := 0 to index - 1 do begin
    node := node.next;
  end;

  get := node.value;
end;

(**
 * Replaces the element at the specified position in this list with the
 * specified element.
 *
 * @param index index of the element to replace
 * @param element element to be stored at the specified position
 * @return the element previously at the specified position
 *)
function LinkedList.set_(index: longInt; element: Object_) : Object_;
var
  node: LinkedListNode;
  original: Object_;
  i: longInt;
begin
  if index < 1 then begin
    original := first.value;
    first.value := element;
  end
  else begin
    node := first;

    for i := 0 to index - 1 do begin
      node := node.next;
    end;

    original := node.value;
    node.value := element;
  end;

  set_ := original;
end;

(**
 * Removes the element at the specified position in this list.
 *
 * @param index the index of the element to be removed
 * @return the element previously at the specified position
 *)
function LinkedList.remove(index: longInt) : Object_;
var
  node: LinkedListNode;
  removed: Object_;
  i: longInt;
begin
  if index < 1 then begin
    node := first;
    removed := node.value;
    removeNode(node);
    freeAndNil(node);
  end
  else begin
    node := first;

    for i := 0 to index - 1 do begin
      node := node.next;
    end;

    removed := node.value;
    removeNode(node);
    freeAndNil(node);
  end;

  dec(count);
  remove := removed;
end;

(**
 * Returns the number of elements in this list.
 *
 * @return the number of elements in this list
 *)
function LinkedList.size() : longInt;
begin
  size := count;
end;

(**
 * Removes all of the elements from this list.
 *)
procedure LinkedList.clear();
begin
  while first <> nil do begin
    remove(0);
  end;
end;

(**
 * Returns a string representation of the object.
 *
 * @return a string representation of the object.
 *)
function LinkedList.toString_() : String_;
var
  sb: StringBuilder;
  str: String_;
  node: LinkedListNode;
begin
  sb := StringBuilder.create();
  str := String_.create('[');
  sb.append(str);
  freeAndNil(str);
  node := first;

  if first <> nil then begin
    if node.value = nil then begin
      str := String_.create('null');
    end
    else begin
      str := node.value.toString_();
    end;

    sb.append(str);
    freeAndNil(str);
    node := node.next;
  end;

  while node <> nil do begin
    str := String_.create(', ');
    sb.append(str);
    freeAndNil(str);

    if node.value = nil then begin
      str := String_.create('null');
    end
    else begin
      str := node.value.toString_();
    end;

    sb.append(str);
    freeAndNil(str);
    node := node.next;
  end;

  str := String_.create(']');
  sb.append(str);
  freeAndNil(str);
  str := sb.toString_();
  freeAndNil(sb);
  toString_ := str;
end;

end.

