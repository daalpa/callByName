#ifndef CALL_BY_NAME_H
#define CALL_BY_NAME_H

#include <string>
#include <map>

class CallableByName {
public:
	virtual void run() const = 0;
};

extern std::map<std::string, CallableByName*> functionContainer;
void registerFunction(const std::string& name, CallableByName* function);
void callFunction(const std::string name);

#define FUNCTION_CALL_BY_NAME(NAME) 	             \
	class NAME : public CallableByName {         \
	public:                                      \
		NAME () {                            \
                    registerFunction(#NAME,this);    \
                };                                   \
		virtual void run() const override;   \
        };                                           \
        static NAME object##NAME ;                   \
        void NAME :: run() const 
        


#endif //CALL_BY_NAME_H