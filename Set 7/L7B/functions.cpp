//
// Created by Jarod Spencer1 on 2019-04-15.
//

#include <vector>
#include "functions.h"
#include "starDataStruct.h"

void convertXPos(int i, const int &WIDTH, vector<StarData> &starData)   {
    starData.at(i).starX = (int)((starData.at(i).starX + 1) * WIDTH / 2 );
}

void convertYPos(int i, const int &HEIGHT, vector<StarData> &starData)  {
    starData.at(i).starY = (int)((-starData.at(i).starY + 1 ) * HEIGHT / 2 );
}
