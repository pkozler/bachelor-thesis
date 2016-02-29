/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import java.util.Comparator;

/**
 * Komparátor pro porovnávání testovacích objektů.
 *
 * @author Petr Kozler
 */
public class DummyObjectComparer implements Comparator<DummyObject> {
    
    /**
     * Porovná dva testovací objekty.
     * 
     * @param o1 první objekt
     * @param o2 druhý objekt
     * @return výsledek porovnání
     */
    @Override
    public int compare(DummyObject o1, DummyObject o2) {
        return o1.getI() - o2.getI();
    }
    
}
