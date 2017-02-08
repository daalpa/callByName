/*
 * Daniel Alves Paladim 2015
 */

#ifndef CALL_BY_NAME_H
#define CALL_BY_NAME_H

#include <string>
#include <map>

namespace CBN {

    class CallableByName {
        public:
	    virtual void run() const = 0;
    };

    using Container = std::map<std::string, CallableByName&>;

    void registerFunction(const std::string& name, CallableByName& function);
    void callFunction(const std::string& name);
    const Container& getFunctionContainer();

}

#define FUNCTION_CALL_BY_NAME(NAME) 	             \
	class NAME : public CBN::CallableByName {        \
	public:                                          \
		NAME () {                                    \
                 CBN::registerFunction(#NAME,*this); \
                };                                   \
		virtual void run() const override;           \
        };                                           \
        static NAME instance_##NAME ;                \
        void NAME :: run() const 
        


#endif //CALL_BY_NAME_H
