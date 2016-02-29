/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

/**
 * Třída pro testování knihoven pracujících s objekty.
 *
 * @author Petr Kozler
 */
public class DummyObject implements Comparable<DummyObject> {

    private String str;
    private int i;

    /**
     * Vytvoří testovací objekt.
     * 
     * @param str řetězcový atribut
     * @param i číselný atribut
     */
    public DummyObject(String str, int i) {
        this.str = str;
        this.i = i;
    }

    /**
     * Vrátí hodnotu řetězce.
     * 
     * @return hodnota řetězce
     */
    public String getStr() {
        return str;
    }

    /**
     * Nastaví hodnotu řetězce.
     * 
     * @param str hodnota řetězce
     */
    public void setStr(String str) {
        this.str = str;
    }

    /**
     * Vrátí hodnotu čísla.
     * 
     * @return hodnota čísla
     */
    public int getI() {
        return i;
    }

    /**
     * Nastaví hodnotu čísla.
     * 
     * @param str hodnota čísla
     */
    public void setI(int i) {
        this.i = i;
    }

    /**
     * Vrátí hashcode objektu podle porovnávaného atributu. 
     * 
     * @return hashcode objektu
     */
    @Override
    public int hashCode() {
        int hash = 7;
        hash = 31 * hash + this.i;
        
        return hash;
    }

    /**
     * Určí, zda má objekt stejnou hodnotu porovnávaného atributu jako jiný objekt.
     * 
     * @param obj jiný objekt
     * @return TRUE, pokud je stejná hodnota, jinak FALSE
     */
    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        
        if (getClass() != obj.getClass()) {
            return false;
        }
        
        final DummyObject other = (DummyObject) obj;
        
        if (this.i != other.i) {
            return false;
        }
        
        return true;
    }
    
    /**
     * Vytvoří textovou reprezentaci objektu.
     * 
     * @return textová reprezentace
     */
    @Override
    public String toString() {
        return "DummyObject [str=" + str + ", i=" + i + "]";
    }

    /**
     * Porovná hodnotu atributu objektu s hodnotou atributu jiného objektu.
     * 
     * @param o jiný objekt
     * @return výsledek porovnání
     */
    @Override
    public int compareTo(DummyObject o) {
        return this.i - o.i;
    }

}
