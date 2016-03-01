unit LinkedListUnit;

{$mode objfpc}{$H+}

interface

uses
  StringUnit;

type
  LinkedListNode = class
    private
      var
        next: LinkedListNode;
        previous: LinkedListNode;
        value: TObject;
  end;

  LinkedList = class
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
  StringBuilderUint, Classes, SysUtils;

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

constructor LinkedList.create();
begin
  count := 0;
  first := nil;
  last := nil;
end;

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

function LinkedList.add(e: TObject) : boolean;
var
  newNode: LinkedListNode;
begin
  newNode := LinkedListNode.create();
  newNode.value := e;
  addLast(newNode);
  inc(count);
  add := true;
end;

procedure LinkedList.add(index: longInt; element: TObject);
var
  node, newNode: LinkedListNode;
  i: longInt;
begin
  newNode := LinkedListNode.create();
  newNode.value := element;

  if index < 1 then begin
    addFirst(newNode);
  end
  else begin
    node := first;

    for i := 0 to index - 1 do begin
      node := node.next;
    end;

    addBefore(node, newNode);
  end;

  inc(count);
end;

function LinkedList.get(index: longInt) : TObject;
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

function LinkedList.set_(index: longInt; element: TObject) : TObject;
var
  node: LinkedListNode;
  original: TObject;
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

function LinkedList.remove(index: longInt) : TObject;
var
  node: LinkedListNode;
  removed: TObject;
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

function LinkedList.size() : longInt;
begin
  size := count;
end;

function LinkedList.isEmpty() : boolean;
begin
  isEmpty := (count = 0);
end;

procedure LinkedList.clear();
begin
  while first <> nil do begin
    remove(0);
  end;
end;

function LinkedList.toString() : ansiString;
var
  sb: StringBuilder;
  str: String_;
  node: LinkedListNode;
begin
  sb := StringBuilder.create();
  str := '[';
  sb.append(str);
  freeAndNil(str);
  node := first;

  if first <> nil then begin
    str := node.value.toString();
    sb.append(str);
    freeAndNil(str);
    node := node.next;
  end;

  while node <> nil do begin
    str := ', ';
    sb.append(str);
    freeAndNil(str);
    str := node.value.toString();
    sb.append(str);
    freeAndNil(str);
    node := node.next;
  end;

  str := ']';
  sb.append(str);
  freeAndNil(str);
  str := sb.toString();
  freeAndNil(sb);
  toString := str.toString();
end;

function LinkedList.toString() : String_;
begin
  toString := String_.create(ToString());
end;

end.

