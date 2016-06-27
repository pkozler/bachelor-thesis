program Stromy;

type
  PTUzelStromu = ^TUzelStromu;
  TUzelStromu = record
    hodnota: char;
    levy: PTUzelStromu;
    pravy: PTUzelStromu;
  end;

var
  preorderIndex: longint;
  radka: ansistring;
  preorder: ansistring;
  inorder: ansistring;
  pocetStromu: longint;
  indexMezery: longint;
  strom: PTUzelStromu;
  i: longint;

(*
 * Vytvori novy uzel stromu
 * @param this odkaz na uzel
 * @param hodnota hodnota uzlu  
 *) 
procedure TUzelStromu_init(var this: TUzelStromu; hodnota: char);
begin
  this.hodnota := hodnota;
  this.levy := nil;
  this.pravy := nil;
end;

(*
 * Hleda znak v retezci mezi indexy <code>pocatecniIndex</code> a <code>koncovyIndex</code>. Vrati index v retezci, pokud je znak nalezen. Jinak vrati -1.
 * @param retezec retezec, ve kterem se hleda znak
 * @param znak znak, ktery se hleda v retezci
 * @param pocatecniIndex pocatecni index, od ktereho se hleda znak v retezci
 * @param koncovyIndex koncovy index, do ktereho se hleda znak v retezci
 * @return index v retezci, pokud je znak nalezen, jinak vrati -1      
 *)              
function hledejZnak(retezec: ansistring; znak: char; pocatecniIndex: integer; koncovyIndex: integer): longint;
var 
  index: longint;
  i: longint;

begin
  index := -1;
  
  for i := pocatecniIndex to (koncovyIndex) do begin
    if (znak = retezec[i]) then begin
      index := i;
      break;
    end;
  end;
  
  hledejZnak := index;
end;

(*
 * Rekurzivne vytvori a vrati strom ze zadane casti preorder a inorder pruchodu
 * @param preoder preorder vypis stromu
 * @param inorder inorder vypis stromu
 * @param pocatecniIndex pocatecni index v inorder vypisu stromu
 * @param koncovyIndex koncovy index v inorder vypisu stromu
 * @return koren vytvoreneho stromu   
 *)                 
function vytvorStromR(preorder: ansistring; inorder: ansistring; pocatecniIndex: longint; koncovyIndex: longint): PTUzelStromu;
var
  inorderIndex: longint;
  uzelStromu: PTUzelStromu;
  
begin
  inorderIndex := 1;
  
  if (pocatecniIndex > koncovyIndex) then begin
    vytvorStromR := nil;
  end
  else begin
    new(uzelStromu);
    TUzelStromu_init(uzelStromu^, preorder[preorderIndex]);
    inc(preorderIndex);
       
    if (pocatecniIndex = koncovyIndex) then begin //Je jen jeden prvek, neni zadny dalsi podstrom, rekurze konci
      vytvorStromR := uzelStromu;
    end
    else begin //Najde znak v inorder pruchodu (koren, ktery se postupne bere z preorder pruchodu) a rekurzivne zavola stejnou metodu pro prave a leve prvky od nalezeneho znaku
      inorderIndex := hledejZnak(inorder, uzelStromu^.hodnota, pocatecniIndex, koncovyIndex);
      uzelStromu^.levy := vytvorStromR(preorder, inorder, pocatecniIndex, inorderIndex - 1);
      uzelStromu^.pravy := vytvorStromR(preorder, inorder, inorderIndex + 1, koncovyIndex);
      
      vytvorStromR := uzelStromu; 
    end;
  end;
end;

(*
 * Vytvori a vrati strom na zaklade jeho preorder a inorder vypisu
 * @param preorder preorder vypis stromu
 * @param inorder inorder vypis stromu
 * @return koren vytvoreneho stromu    
 *)        
function vytvorStrom(preorder: ansistring; inorder: ansistring): PTUzelStromu;
begin
  preorderIndex := 1;
  vytvorStrom := vytvorStromR(preorder, inorder, 1, length(inorder));
end;

(*
 * Vypise strom postorderem
 * @param strom strom, ktery ma byt vypsan postorderem  
 *)        
procedure vypisPostorder(strom: PTUzelStromu);
begin
  if (strom = nil) then begin
    ;
  end
  else begin
    vypisPostorder(strom^.levy);
    vypisPostorder(strom^.pravy);
    write(strom^.hodnota);
  end;
end;

(*
 * Vstupni bod programu
 *)
begin
  readln(pocetStromu);
  
  for i := 0 to (pocetStromu - 1) do begin
    readln(radka);
    
    indexMezery := pos(' ', radka);
    preorder := copy(radka, 1, indexMezery - 1);
    inorder := copy(radka, indexMezery + 1, length(radka) - indexMezery);
    strom := vytvorStrom(preorder, inorder);
    
    vypisPostorder(strom);
    writeln();
  end;
end.
