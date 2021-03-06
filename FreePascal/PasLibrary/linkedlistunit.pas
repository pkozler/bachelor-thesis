unit LinkedListUnit;

{$mode objfpc}{$H+}

interface

uses
  StringUnit, ListUnit;

(*
    LinkedListNode structure represents the node in the doubly-linked list
    containing the element and the references to the next and the previous node in the list.
 *)
type
  LinkedListNode = class
    private
      var
        // stored element
        value: Object_;
        // next node in the list
        next: LinkedListNode;
        // previous node in the list
        previous: LinkedListNode;
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
        // list element count
        count: longInt;
        // first node in the list
        first: LinkedListNode;
        // last node in the list
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
  // setting the empty nodes
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

(*
    Destructs the LinkedList.
 *)
destructor LinkedList.destroy();
begin
  clear();
  inherited;
end;

(*
    Adds the new node after the specified existing node in the list and updates the references.
 *)
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

(*
    Adds the new node before the specified existing node in the list and updates the references.
 *)
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

(*
    Adds the new node to the beginning of the list and updates the references.
 *)
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

(*
    Adds the new node to the end of the list and updates the references.
 *)
procedure LinkedList.addLast(newNode: LinkedListNode);
begin
  if last = nil then begin
    addFirst(newNode);
  end
  else begin
    addAfter(last, newNode);
  end;
end;

(*
    Removes the specified existing node from the list and updates the references.
 *)
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
  // creating the node for storing the element
  newNode := LinkedListNode.create();
  newNode.value := e;
  // adding as the last node of the list
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
  // creating the node for storing the element
  newNode := LinkedListNode.create();
  newNode.value := element;

  // adding as the first node of the list if the list is currently empty
  if count < 1 then begin
    addFirst(newNode);
  end
  else begin
    node := first;

    // adding before the first node of the list if the index is 0
    if index < 1 then begin
      addBefore(node, newNode);
    end
    else begin

      for i := 1 to index - 1 do begin
        node := node.next;
      end;

      // adding after the node found on the specified position, if the index is not 0
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

  // iterating over the list to the node on the specified position
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
  // setting the first node if the index is 0
  if index < 1 then begin
    original := first.value;
    first.value := element;
  end
  else begin
    node := first;

    for i := 0 to index - 1 do begin
      node := node.next;
    end;

    // setting the node on the specified position
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
  // removing the first node if the index is 0
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

    // removing the node on the specified position
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
  // deallocating the memory of the each list node after removing it
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
  // create StringBuilder for appending the text
  sb := StringBuilder.create();
  str := String_.create('[');
  sb.append(str);
  freeAndNil(str);
  node := first;

  // append first element string representation
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

  // append another elements string representation
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

  // create Java-like string
  str := String_.create(']');
  sb.append(str);
  freeAndNil(str);
  str := sb.toString_();
  freeAndNil(sb);
  toString_ := str;
end;

end.

