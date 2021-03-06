//
//  StockData.swift
//  StockCheck
//
//  Created by Rushi Patel on 2021-03-01.
//

import Foundation
public class dataSTK{
    var c : Double = 0;
    var h : Double = 0;
    var l : Double = 0;
    var o : Double = 0;
    var pc : Double = 0;
    var t : String = "";
   public  init(c: Double, h: Double, l : Double, o : Double, pc : Double, t: String) {
        self.c = c;
        self.h = h;
        self.l = l;
        self.o = o;
        self.pc = pc;
        self.t = t;
    }
    required init(from decoder:Decoder) throws {
        
      }
    public init() {
        c = 0; h = 0; o = 0; l = 0; pc = 0; t = "";
    }
}
