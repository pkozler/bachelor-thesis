Toto CD je sou��st� bakal��sk� pr�ce na t�ma "Vytvo�en� knihoven s definovan�m rozhran�m v jazyc�ch C, C++, C# a FreePascal" na Kated�e informatiky a v�po�etn� techniky Fakulty aplikovan�ch v�d Z�pado�esk� univerzity v Plzni.
Autor: Petr Kozler
Datum: 23.06.2016

Popis adres��ov� struktury:

Thesis - obsahuje adres��e se soubory textu bakal��sk� pr�ce:
  tex - obsahuje zdrojov� text pr�ce pro sazbu v typografick�m syst�mu TeX spolu s dal��mi nezbytn�mi daty
  pdf - obsahuje v�stupn� dokument sazby ve form�tu PDF

Libraries - obsahuje adres��e s p�vodn� podobou zdrojov�ch k�d� (tj. v podob� p�ed jejich ulo�en�m do XML dokument� pomoc� aplikace pro spr�vu zdrojov�ho k�du) vytvo�en�ch knihoven a se zdrojov�mi k�dy programov�ho vybaven� pro jejich testov�n�:
  C - obsahuje mj. adres�� CLibrary se zdrojov�mi k�dy knihoven v jazyce C a podadres��em tests se zdrojov�mi k�dy modul� pro jednotkov� testy t�chto knihoven; adres��e jsou vytvo�eny jako projekty v�vojov�ho prost�ed� Netbeans 8.0.2
  CPlusPlus - obsahuje mj. adres�� CppLibrary se zdrojov�mi k�dy knihoven v jazyce C++ a podadres��em tests se zdrojov�mi k�dy modul� pro jednotkov� testy t�chto knihoven; adres��e jsou vytvo�eny jako projekty v�vojov�ho prost�ed� Netbeans 8.0.2
  CSharp - obsahuje mj. adres�� CsLibrary se zdrojov�mi k�dy knihoven v jazyce C# a d�le adres�� CsLibraryTest se zdrojov�mi k�dy t��d pro jednotkov� testy; adres��e jsou vytvo�eny jako projekty v�vojov�ho prost�ed� Visual Studio Community 2015
  FreePascal - obsahuje mj. adres�� PasLibrary se zdrojov�mi k�dy knihoven v jazyce Free Pascal a d�le adres�� PasLibraryTest se zdrojov�mi k�dy t��d pro jednotkov� testy; adres��e jsou vytvo�eny jako projekty v�vojov�ho prost�ed� Lazarus 1.4.4
  IOLibraryTestRunner - obsahuje zdrojov� soubory PHP skriptu pro automatizovan� testov�n� knihoven (ve v�ech pou�it�ch programovac�ch jazyc�ch) ur�en�ch k prov�d�n� vstupn�/v�stupn�ch operac�*

CodeManager - je ko�enov�m adres��em aplikace pro spr�vu zdrojov�ho k�du vytvo�en� v jazyce Java, obsahuje mj. adres��e:
  src - obsahuje bal�ky se zdrojov�mi k�dy a dal��mi soubory pot�ebn�mi pro spu�t�n� aplikace
  doc - obsahuje program�torskou dokumentaci vygenerovanou n�strojem Javadoc (u�ivatelsk� p��ru�ka je p�ilo�ena k textu bakal��sk� pr�ce)
  bin - obsahuje spustiteln� .jar soubor aplikace a adres�� s daty (XML soubory)
  test - obsahuje t��dy pro jednotkov� testy j�dra aplikace (GUI bylo testov�no manu�ln�)

CodeConverter - obsahuje zdrojov� soubory n�stroje pro automatickou konverzi jednoduch�ch konstrukc� v k�du z jazyka Java do ostatn�ch pou�it�ch jazyk� (n�stroj disponuje webov�m rozhran�m a logika je naprogramov�na v jazyce JavaScript)

*pozn.: v�echny 4 adres��e vytvo�en�ch knihoven obsahuj� krom� uveden�ch podadres��� t� podadres��e PrintStreamTest a ScannerTest, obsahuj�c� zdrojov� k�dy utilit pro testov�n� knihoven ur�en�ch k IO operac�m; tyto utility jsou pot� vyu��v�ny n�strojem pro automatizovan� testov�n�