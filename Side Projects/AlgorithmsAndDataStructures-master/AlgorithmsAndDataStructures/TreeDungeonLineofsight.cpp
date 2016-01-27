//
//  TreeDungeonLineofsight.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 9/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "ResourcePath.hpp"

void lineOfSight(class Maps& Map, class Character& Character){
    int charX = (Character.getPlayerX() / 32);
    int charY = (Character.getPlayerY() / 32);
    
    for(int i = 0; i < MAPSIZE; ++i){
        for(int j = 0; j < MAPSIZE; ++j){
            Map.setLOS(i, j, 'x');
        }
    }
    
    for (int x0 = charX - MAPSIZE * 2; x0 < charX + MAPSIZE; x0++){
        for (int y0 = charY - MAPSIZE * 2; y0 < charY + MAPSIZE; y0++){
            int dx = abs(charX - x0);
            int dy = abs(charY - y0);
            int x = charX;
            int y = charY;
            int n = 1 + dx + dy;
            int x_inc = (x0 > charX) ? 1 : -1;
            int y_inc = (y0 > charY) ? 1 : -1;
            int error = dx - dy;
            
            for (; n > 0; n--){
                if (error > 0){
                    x += x_inc;
                    error -= dy;
                    if (Map.getCurrentMap(x, y) == 'x'){
                        break;
                    }
                    if (Map.getCurrentMap(x, y) == 'z'){
                        break;
                    }
                    if (Map.getCurrentMap(x, y) == 'o'){
                        Map.setLOS(x, y, 'o');
                    }
                    if (Map.getCurrentMap(x, y) == 't'){
                        Map.setLOS(x, y, 'o');
                    }
                    if (Map.getCurrentMap(x, y) == 'm'){
                        Map.setLOS(x, y, 'o');
                    }
                }
                
                else{
                    y += y_inc;
                    error += dx;
                    if (Map.getCurrentMap(x, y) == 'x'){
                        break;
                    }
                    if (Map.getCurrentMap(x, y) == 'z'){
                        break;
                    }
                    if (Map.getCurrentMap(x, y) == 'o'){
                        Map.setLOS(x, y, 'o');
                    }
                    if (Map.getCurrentMap(x, y) == 't'){
                        Map.setLOS(x, y, 'o');
                    }
                    if (Map.getCurrentMap(x, y) == 'm'){
                        Map.setLOS(x, y, 'o');
                    }
                }
            }
        }
        Map.setLOS(charX, charY, 'o');
    }
}
