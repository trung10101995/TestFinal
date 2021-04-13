//
//  File.swift
//  NewFinal
//
//  Created by Nguyễn Trung on 4/13/21.
//  Copyright © 2021 Nguyễn Trung. All rights reserved.
//

import KingIdSDKOld

class x {
    public func congifKingIdLoginApple(clientID: String, secretKey: String) {
        KingIdSDKController.sharedInstance().configure(clientID, clientSecret: secretKey)
        KingIdSDKController.sharedInstance().debugMode = true
        KingIdSDKController.sharedInstance().enableAppleLogin = true
        KingIdSDKController.sharedInstance().disableExitLogin = false
    
    }
}
