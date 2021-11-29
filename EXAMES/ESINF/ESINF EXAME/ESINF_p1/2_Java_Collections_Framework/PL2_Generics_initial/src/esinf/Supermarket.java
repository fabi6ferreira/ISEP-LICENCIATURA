/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package esinf;

import java.time.LocalDate;
import java.util.*;
import java.util.Map.Entry;

/**
 *
 * @author DEI-ISEP
 */
public class Supermarket {

    Map<Invoice, Set<Product>> m;

    Supermarket() {
        m = new HashMap<>();
    }

    // Reads invoices from a list of String
    void getInvoices(List<String> l) throws Exception {
        Iterator lista = l.iterator();

        String[] linha = ((String) lista.next()).split(",");

        while (linha != null && linha[0].equalsIgnoreCase("I")) {
            String ref = linha[1];
            String date = linha[2];
            Invoice inv = new Invoice(ref, date);
            Set<Product> set = new HashSet();
            if (lista.hasNext()) {
                linha = ((String) lista.next()).split(",");
            } else {
                break;
            }
            while (linha != null && linha[0].equalsIgnoreCase("P")) {
                String id = (String) linha[1];
                int qtd = Integer.valueOf(linha[2]);
                long price = Long.valueOf(linha[3]);
                Product p = new Product(id, qtd, price);
                set.add(p);
                if (lista.hasNext()) {
                    linha = ((String) lista.next()).split(",");
                } else {
                    break;
                }
                m.put(inv, set);

            }

        }
    }

    // returns a set in which each number is the number of products in the r
    // invoice 
    Map<Invoice, Integer> numberOfProductsPerInvoice() {
        Map<Invoice, Integer> num_prod = new HashMap();
        for (Entry entry : m.entrySet()) {
            Invoice inv = (Invoice) entry.getKey();
            int count = m.get(inv).size();
            num_prod.put(inv, count);

        }
        return num_prod;
    }

    // returns a Set of invoices in which each date is >d1 and <d2
    Set<Invoice> betweenDates(LocalDate d1, LocalDate d2
    ) {
        Set<Invoice> set = new HashSet();
        for (Entry entry : m.entrySet()) {
            Invoice inv = (Invoice) entry.getKey();
            LocalDate inv_date = inv.getDate();
            if ((inv_date.compareTo(d1) > 0) && inv_date.compareTo(d2) < 0) {
                set.add(inv);
            }
        }
        return set;
    }

    //returns the sum of the price of the product in all the invoices
    long totalOfProduct(String productId) {
        long total = 0;
        Iterator itValues = m.values().iterator();
        while (itValues.hasNext()) {
            Set<Product> set = (Set<Product>) itValues.next();
            Iterator itSet = set.iterator();
            while (itSet.hasNext()) {
                Product p = (Product) itSet.next();
                if (p.getIdentification().equalsIgnoreCase(productId)) {
                    total += p.getQuantity() * p.getPrice();

                }
            }
        }
        return total;
    }

    // converts a map of invoices and troducts to a map which key is a product 
    // identification and the values are a set of the invoice references 
    // in which it appearss
    Map<String, Set<Invoice>> convertInvoices() {
        Map<String, Set<Invoice>> converted = new HashMap();

        for (Set<Product> productSet : m.values()) {

            for (Product prod : productSet) {
                if (!converted.containsKey(prod.getIdentification())) {
                    Iterator itKey = m.keySet().iterator();
                    Set<Invoice> invSet = new HashSet();
                    while (itKey.hasNext()) {
                        Invoice inv = (Invoice) itKey.next();
                        if (m.get(inv).contains(prod)) {
                            invSet.add(inv);
                        }
                    }
                    converted.put(prod.getIdentification(), invSet);
                }
            }

        }
        return converted;

    }
}
