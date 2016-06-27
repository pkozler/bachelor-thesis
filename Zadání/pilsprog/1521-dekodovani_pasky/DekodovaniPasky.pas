program DekodovaniPasky;

const
  (* Znak reprezentujici nulu *)
  NULA = ' ';
  (* Znak reprezentujici jednicku *)
  JEDNA = 'o';
  (* Znak reprezentujici konec kusu pasky *)
  KONEC = '_';
  (*   *)
  INDEX_ZACATEK = 3;
  (*  *)
  INDEX_KONEC = 10;
  (*  *)
  INDEX_VODICI_PAS = 7;
var
  radka: ansistring;

(*
 * Dekoduje a vrati znak z jedne radky derne pasky
 * @param radka radka derne pasky obsahujici jeden znak zaznamenany pomoci sedmi bitu
 * @return znak z jedne radky derne pasky   
 *)        
function dekodujZnak(radka: ansistring): char;
var
  znak: longword;
  i: longint;
  
begin
  znak := 0;
  
  for i := INDEX_ZACATEK to INDEX_KONEC do begin
    if (i <> INDEX_VODICI_PAS) then begin
      znak := znak shl 1;
      
      if (radka[i] = JEDNA) then begin
        znak := znak or 1;
      end;
    end;
  end;
  
  dekodujZnak := chr(znak);
end;
    
begin
  readln(radka); //Nacteni prvni radky, kterou nevyuzijeme - obsahuje podtrzitka
  
  readln(radka);
  while (radka[1] <> KONEC) do begin
    write(dekodujZnak(radka));
    readln(radka)
  end; 
  
  writeln();
end.