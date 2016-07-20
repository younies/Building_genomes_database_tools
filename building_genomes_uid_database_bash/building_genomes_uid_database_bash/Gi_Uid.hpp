//
//  Gi_Uid.hpp
//  building_genomes_uid_database_bash
//
//  Created by Younies Mahmoud on 7/20/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#ifndef Gi_Uid_hpp
#define Gi_Uid_hpp

#include "headers.h"

class Gi_Uid {
    vector < pair<LONGS, LONGS> > gi_uid_map;
    string path_to_gi_uid_file;

public:
    Gi_Uid(string path_to_giuid_file);
    
    
    LONGS getGiFromFile(string path_to_file);
    
    LONGS getTheUId(LONGS gi);
    
};


#endif /* Gi_Uid_hpp */
