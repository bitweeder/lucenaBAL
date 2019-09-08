#include <lucenaBAL/lucenaBAL.hpp>

//	This must be invoked from the global namespace scope. After this, our
//	namespace will be something like `::lucena::bal`.
LBAL_begin_namespace

void A() { }

//	This must be invoked from the unversioned namespace scope. After this, our
//	namespace will be something like `::lucena::bal::inline bal_2`.
LBAL_enter_v_namespace

void B() { }

//	After this, we’ll be back in `::lucena::bal`.
LBAL_exit_v_namespace


//	After this, we’re back at global namespace scope.
LBAL_end_namespace


//	This takes us straight to the versioned namespace scope from the global
//	namespace scope. Our current namespace will be something like
//	`::lucena::bal::inline bal_2`.
LBAL_begin_v_namespace

void B() { }

//	After this, we’re back at global namespace scope.
LBAL_end_v_namespace

int main()
{
	LBAL_::A();		//	Invokes function A() from the unversioned namespace;
					//	resolves to something like `::lucena::bal::A()`.

	LBAL_v_::B();	//	Invoke functions B() and C() from a specific versioned
	LBAL_v_::C();	//	namespace; thes eresolve to something like
					//	`::lucena::bal::inline bal_2::B()` and
					//	`::lucena::bal::inline bal_2::C()`.

	LBAL_::B();		//	Invokes function B() from the regular namespace;
					//	this will be whatever function B() is defined in the
					//	current versioned namespace at the time of compilation.
					//	It will behave as if it resolves to something like
					//	`::lucena::bal::B()`, but the actual fully qualified
					// name will be like `::lucena::bal::inline bal_2::B()`.

	return 0;
}
