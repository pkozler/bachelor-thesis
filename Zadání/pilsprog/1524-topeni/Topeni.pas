program Topeni;

type
  TStringTokenizer = record
    stringToSplit: ansistring;
    splitCharacter: char;
    remainingString: ansistring;
  end;
  TTechnici = array of array of longint;
  TPraveStrany = array of longint;
  TVysledek = array of boolean;

var
  pocetTechniku: longint;
  radka: ansistring;
  technici: TTechnici;
  nalezeno: boolean;
  poprve: boolean;
  vysledek: TVysledek;
  i, j: longint;

(*
 *
 * @param this
 * @param stringToSplit  
 * @param splitCharacter 
 *)
procedure TStringTokenizer_init(var this: TStringTokenizer; stringToSplit: ansistring; splitCharacter: char);
begin
  this.stringToSplit := stringToSplit;
  this.remainingString := stringToSplit;
  this.splitCharacter := splitCharacter;
end;

(*
 * 
 * @param this
 * @return
 *)
function TStringTokenizer_hasNextToken(var this: TStringTokenizer): boolean;
begin
  TStringTokenizer_hasNextToken := (length(this.remainingString) = 0);
end;

(*
 *
 * @param this
 * @return 
 *)
function TStringTokenizer_nextToken(var this: TStringTokenizer): ansistring;
var
  nextToken: ansistring;
  splitCharacterIndex: integer;
begin
  splitCharacterIndex := pos(this.splitCharacter, this.remainingString);
  //writeln('Nalezeno: ', splitCharacterIndex);
  if (splitCharacterIndex > 0) then begin
    nextToken := copy(this.remainingString, 1, splitCharacterIndex - 1);
    if (splitCharacterIndex < length(this.remainingString)) then begin
      this.remainingString := copy(this.remainingString, splitCharacterIndex + 1, length(this.remainingString) - splitCharacterIndex);  
    end
    else begin
      this.remainingString :='';
    end;
    
    TStringTokenizer_nextToken := nextToken;
  end
  else if (length(this.remainingString) > 0) then begin
    nextToken := this.remainingString;
    this.remainingString := '';
    TStringTokenizer_nextToken := nextToken;
  end                           
  else begin            
    TStringTokenizer_nextToken := '';                     
  end;
end;

(*
 * 
 * @param this
 * @return 
 *)
function TStringTokenizer_countTokens(var this: TStringTokenizer): longint;
var
  splitCharacterCount: longint;
  i: longint;
begin
  splitCharacterCount := 0;
  for i := 1 to length(this.stringToSplit) do begin
    if (this.stringToSplit[i] = this.splitCharacter) then begin
      inc(splitCharacterCount);
    end;
  end;
  
  TStringTokenizer_countTokens := splitCharacterCount + 1;
end;

(*
 * Zpracuje radku s jednim technikem a zaznamena jeho ventily do pole techniku
 * @param indexTechnika 
 * @param technik radka obsahujici ventily technika
 * @param technici pole techniku (a jejich ventilu), do ktereho se ventily technika zaznamenaji    
 *)        
procedure zapisTechnika(indexTechnika: longint; technik: ansistring; var technici: TTechnici);
var
  st: TStringTokenizer;
  pocetVentilu: longint;
  ventil: longint;
  i: longint;
  kod: longint;
  
begin
  TStringTokenizer_init(st, technik, ' ');
  pocetVentilu := TStringTokenizer_countTokens(st) - 1;
  ventil := 0;
     
  for i := 0 to (pocetVentilu - 1) do begin
    val(TStringTokenizer_nextToken(st), ventil, kod);
    technici[indexTechnika][ventil - 1] := 1;
  end;     
end;

(*
 * Prohodi sloupce matice techniku tak, aby na prislusne pozici na diagonale byla 1. Vrati <code>true</code>, pokud uspeje, jinak <code>false</code>.
 * @param technici matice techniku 
 * @param indexySloupcu pole obsahujici indexy sloupcu, diky nemu je mozne slouce prehazovat, aniz se prvky realne kopirovaly
 * @param index pozice na diagonale, na ktere se ma vyrobit 1
 * @return <code>true</code>, pokud uspeje, jinak <code>false</code>.       
 *)           
function prohod(var technici: TTechnici; var indexySloupcu: TPraveStrany; index: longint): boolean;
var
  lzeProhodit: boolean;
  indexSloupce: longint;
  pomocna: longint;
  i: longint;

begin  
  lzeProhodit := false;
  indexSloupce := 0;
  pomocna := 0;
  
  for i := index + 1 to (length(technici) - 1) do begin
    if (technici[index, indexySloupcu[i]] = 1) then begin
      lzeProhodit := true;
      indexSloupce := i;
      break;
    end;
  end;
  
  if (lzeProhodit) then begin
    pomocna := indexySloupcu[indexSloupce];
    indexySloupcu[indexSloupce] := indexySloupcu[index];
    indexySloupcu[index] := pomocna;
  end;
  
  prohod := lzeProhodit;
end;  

(*
 * Urci potrebne techniky s vyuzitim Gauss-Jordanovy eliminace
 * @param technici
 * @return  
 *)        
function urciPotrebneTechniky(var technici: TTechnici): TVysledek;
var
  praveStrany: TPraveStrany;
  indexySloupcu: TPraveStrany;
  vysledek: TVysledek;
  i, j, k: longint;

begin  
  setLength(praveStrany, length(technici));
  setLength(indexySloupcu, length(technici));
  setLength(vysledek, length(technici));
  for i := 0 to (length(praveStrany) - 1) do begin
    praveStrany[i] := 1;
    indexySloupcu[i] := i;
    vysledek[i] := false;
  end;

  for i := 0 to (length(technici) - 1) do begin //Overovani, zda na diagonale jsou 1
    if (technici[i, indexySloupcu[i]] <> 1) then begin //Pokud neni na diagonale 1
      if (NOT prohod(technici, indexySloupcu, i)) then begin  //pokusi se ji tam doplnit prohozenim s jinym radkem
        urciPotrebneTechniky := vysledek; //Pokud to nejde, reseni neexsituje, vratime pole plne <code>false</code>
        exit;
      end;
    end;
    
    for j := i + 1 to (length(technici) - 1) do begin //Nulovani prvku pod diagonalou v prislusne radce
      if (technici[i, indexySloupcu[j]] = 1) then begin
        praveStrany[indexySloupcu[j]] := (praveStrany[indexySloupcu[i]] + praveStrany[indexySloupcu[j]]) mod 2;
        for k := 0 to (length(technici) - 1) do begin
          technici[k, indexySloupcu[j]] := (technici[k, indexySloupcu[i]] + technici[k, indexySloupcu[j]]) mod 2; 
        end;
      end;
    end;
  end;
  
  for i := length(technici) - 1 downto 0 do begin //Nulovani prvku nad diagonalou 
    for j := i - 1 downto 0 do begin
      if (technici[i, indexySloupcu[j]] = 1) then begin
        praveStrany[indexySloupcu[j]] := (praveStrany[indexySloupcu[i]] + praveStrany[indexySloupcu[j]]) mod 2;
        for k := 0 to (length(technici) - 1) do begin
          technici[k, indexySloupcu[j]] := (technici[k, indexySloupcu[i]] + technici[k, indexySloupcu[j]]) mod  2; 
        end;
      end;
    end;
  end;
  
  for i := 0 to (length(technici) - 1) do begin
    if (praveStrany[indexySloupcu[i]] = 1) then begin
      vysledek[i] := true;
    end
    else begin
      vysledek[i] := false;
    end;
  end;
  
  urciPotrebneTechniky := vysledek;
end;
  
  
begin
  readln(pocetTechniku);
  
  setLength(technici, pocetTechniku, pocetTechniku);
  for i := 0 to (length(technici) - 1) do begin
    for j := 0 to (length(technici[i]) - 1) do begin
      technici[i, j] := 0;
    end;
  end;
  
  for i := 0 to (pocetTechniku - 1) do begin
    readln(radka); 
    zapisTechnika(i, radka, technici);
  end;
  
  nalezeno := false;
  poprve := true;
  vysledek := urciPotrebneTechniky(technici);
  for i := 0 to (length(vysledek) - 1) do begin
    if (vysledek[i]) then begin
      nalezeno := true;
      if (poprve) then begin
        write(i + 1);
        poprve := false;
      end
      else begin
        write(' ', (i + 1));
      end;
    end;
  end;
  
  if (NOT nalezeno) then begin
    writeln('-1');
  end; 

end.
