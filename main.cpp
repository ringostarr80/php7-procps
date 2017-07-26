#include <phpcpp.h>
#include "RingoLeese/ProcPS.hpp"

using namespace std;

namespace RL = RingoLeese;

/**
 * tell the compiler that the get_module is a pure C function
 */
extern "C" {
	/**
	 *  Function that is called by PHP right after the PHP process
	 *  has started, and that returns an address of an internal PHP
	 *  strucure with all the details and features of your extension
	 *
	 *  @return void*   a pointer to an address that is understood by PHP
	 */
	PHPCPP_EXPORT void *get_module()
	{
		static Php::Extension extension("procps", "0.2");

		Php::Namespace topNamespace("RingoLeese");

		Php::Class<RL::ProcPS> procps("ProcPS");
		procps.method<&RL::ProcPS::__construct>("__construct");
		procps.method<&RL::ProcPS::Read>("Read", {
			Php::ByVal("options", Php::Type::Numeric, false)
		});
		procps.property("FILLMEM", PROC_FILLMEM, Php::Const);			// 0x000001
		procps.property("FILLCOM", PROC_FILLCOM, Php::Const);			// 0x000002
		procps.property("FILLENV", PROC_FILLENV, Php::Const);			// 0x000004
		procps.property("FILLUSR", PROC_FILLUSR, Php::Const);			// 0x000008
		procps.property("FILLGRP", PROC_FILLGRP, Php::Const);			// 0x000010
		procps.property("FILLSTATUS", PROC_FILLSTATUS, Php::Const);		// 0x000020
		procps.property("FILLSTAT", PROC_FILLSTAT, Php::Const);			// 0x000040
		procps.property("FILLWCHAN", PROC_FILLWCHAN, Php::Const);		// 0x000080
		procps.property("FILLARG", PROC_FILLARG, Php::Const);			// 0x000100
		procps.property("FILLCGROUP", PROC_FILLCGROUP, Php::Const);		// 0x000200
		procps.property("FILLSUPGRP", PROC_FILLSUPGRP, Php::Const);		// 0x000400
		procps.property("FILLOOM", PROC_FILLOOM, Php::Const);			// 0x000800
		procps.property("PID", PROC_PID, Php::Const);					// 0x001000 -> illegal?
		procps.property("LOOSE_TASKS", PROC_LOOSE_TASKS, Php::Const);	// 0x002000
		procps.property("UID", PROC_UID, Php::Const);					// 0x004000 -> illegal?
		procps.property("FILLNS", PROC_FILLNS, Php::Const);				// 0x008000
		procps.property("EDITCGRPCVT", PROC_EDITCGRPCVT, Php::Const);	// 0x010000
		procps.property("EDITCMDLCVT", PROC_EDITCMDLCVT, Php::Const);	// 0x020000
		procps.property("EDITENVRCVT", PROC_EDITENVRCVT, Php::Const);	// 0x040000
		procps.property("FILLSYSTEMD", PROC_FILLSYSTEMD, Php::Const);	// 0x080000
		
		topNamespace.add(move(procps));

		extension.add(move(topNamespace));

		// return the extension
		return extension;
	}
}
