//
//  manager.h
//  CPP
//
//  Created by 김서현 on 8/1/24.
//

#ifndef manager_h
#define manager_h

#include "person.h"

class Manager : public Person {
public:
    Manager();
    Manager(string name, int age);
    ~Manager(); 
};


#endif /* manager_h */
