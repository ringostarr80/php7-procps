#include <iostream>
#include <proc/readproc.h>
#include <phpcpp.h>

using namespace std;

namespace RingoLeese
{
	class ProcPS : public Php::Base
	{
	private:

	public:
		ProcPS();
		virtual ~ProcPS();

		void __construct();
		Php::Value Read(Php::Parameters &params);
	};
}
