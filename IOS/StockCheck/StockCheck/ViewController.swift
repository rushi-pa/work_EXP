//
//  ViewController.swift
//  StockCheck
//
//  Created by Rushi Patel on 2021-03-01.
//https://finnhub.io/api/v1/quote?symbol=BNS&token=c0umc5f48v6o5kk5d2sg

import UIKit
class ViewController: UIViewController {
    let stkurl = "https://finnhub.io/api/v1/quote?symbol=BNS&token=c0umc5f48v6o5kk5d2sg";
    var data = dataSTK();
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        Timer.scheduledTimer(timeInterval: 1.0, target: self, selector: #selector(updateCounter), userInfo: nil, repeats: true)
    }
    

    @objc func updateCounter() {
        //example functionality
        print("baba");
        getData();
    }

    private func getData(){
        let url = URL(string: stkurl + "films/")!

        let task = URLSession.shared.dataTask(with: url, completionHandler: { (data, response, error) in
          if let error = error {
            print("Error with fetching films: \(error)")
            return
          }
          
          guard let httpResponse = response as? HTTPURLResponse,
                (200...299).contains(httpResponse.statusCode) else {
            print("Error with the response, unexpected status code: \(response)")
            return
          }

          if let data = data,
            let filmSummary = try? JSONDecoder().decode(dataSTK.self, from: data) {
          //  completionHandler(filmSummary.results ?? [])
          }
        })
        task.resume()
        
        
    
    }
    
}
