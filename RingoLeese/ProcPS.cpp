#include "ProcPS.hpp"

namespace RingoLeese
{
	ProcPS::ProcPS()
	{
		
	}

	ProcPS::~ProcPS()
	{
		
	}

	void ProcPS::__construct()
	{

	}

	Php::Value ProcPS::Read(Php::Parameters &params)
	{
		int options = 0;
		if (params.size() == 1) {
			options = params[0];
		}

		options&= 0x0FAFFF; // exlude PROC_PID and PROC_UID, because of crashing behaviour.

		Php::Value processes;
		PROCTAB* proc = openproc(options);
		proc_t *proc_info;
		int processCounter = 0;
		while((proc_info = readproc(proc, NULL)) != NULL) {
			processCounter++;
			Php::Value process;

			process["tid"] = proc_info->tid; // 0
			process["ppid"] = proc_info->ppid; // 32
			process["maj_delta"] = (long)proc_info->maj_delta;
			process["min_delta"] = (long)proc_info->min_delta;
			process["pcpu"] = (int)proc_info->pcpu;
			process["state"] = proc_info->state; // 32
			process["pad_1"] = proc_info->pad_1;
			process["pad_2"] = proc_info->pad_2;
			process["pad_3"] = proc_info->pad_3;
			process["utime"] = (long)proc_info->utime; // 64
			process["stime"] = (long)proc_info->stime; // 64
			process["cutime"] = (long)proc_info->cutime; // 64
			process["cstime"] = (long)proc_info->cstime; // 64
			process["start_time"] = (long)proc_info->start_time; // 64
			process["signal"] = proc_info->signal; // 32
			process["blocked"] = proc_info->blocked; // 32
			process["sigignore"] = proc_info->sigignore; // 32
			process["sigcatch"] = proc_info->sigcatch; // 32
			process["_sigpnd"] = proc_info->_sigpnd; // 32
			process["start_code"] = (long)proc_info->start_code; // 64
			process["end_code"] = (long)proc_info->end_code; // 64
			process["start_stack"] = (long)proc_info->start_stack; // 64
			process["kstk_esp"] = (long)proc_info->kstk_esp; // 64
			process["kstk_eip"] = (long)proc_info->kstk_eip; // 64
			process["wchan"] = (long)proc_info->wchan; // 32
			process["priority"] = proc_info->priority; // 64
			process["nice"] = proc_info->nice; // 64
			process["rss"] = proc_info->rss; // 64
			process["alarm"] = proc_info->alarm;
			process["size"] = proc_info->size; // 1
			process["resident"] = proc_info->resident; // 1
			process["share"] = proc_info->share; // 1
			process["trs"] = proc_info->trs; // 1
			process["lrs"] = proc_info->lrs;
			process["drs"] = proc_info->drs; // 1
			process["dt"] = proc_info->dt;
			process["vm_size"] = (long)proc_info->vm_size; // 32
			process["vm_lock"] = (long)proc_info->vm_lock; // 32
			process["vm_rss"] = (long)proc_info->vm_rss; // 32
			process["vm_data"] = (long)proc_info->vm_data; // 32
			process["vm_stack"] = (long)proc_info->vm_stack; // 32
			process["vm_swap"] = (long)proc_info->vm_swap;
			process["vm_exe"] = (long)proc_info->vm_exe; // 32
			process["vm_lib"] = (long)proc_info->vm_lib; // 32
			process["rtprio"] = (long)proc_info->rtprio; // 64
			process["sched"] = (long)proc_info->sched; // 64
			process["vsize"] = (long)proc_info->vsize; // 64
			process["rss_rlim"] = (long)proc_info->rss_rlim; // 64
			process["flags"] = (long)proc_info->flags; // 64
			process["min_flt"] = (long)proc_info->min_flt; // 64
			process["maj_flt"] = (long)proc_info->maj_flt; // 64
			process["cmin_flt"] = (long)proc_info->cmin_flt; // 64
			process["cmaj_flt"] = (long)proc_info->cmaj_flt; // 64
			if (proc_info->environ != NULL) {
				process["environ"] = *proc_info->environ; // 4
			}
			if (proc_info->cmdline != NULL) {
				process["cmdline"] = *proc_info->cmdline; // 2
			}
			if (proc_info->cgroup != NULL) {
				process["cgroup"] = *proc_info->cgroup; // 512
			}
			process["supgid"] = proc_info->supgid; // 32
			process["supgrp"] = proc_info->supgrp;
			process["euser"] = proc_info->euser; // 8
			process["ruser"] = proc_info->ruser; // 32
			process["suser"] = proc_info->suser; // 32
			process["fuser"] = proc_info->fuser; // 32
			process["rgroup"] = proc_info->rgroup; // 32
			process["egroup"] = proc_info->egroup; // 32
			process["sgroup"] = proc_info->sgroup;
			process["fgroup"] = proc_info->fgroup;
			process["cmd"] = proc_info->cmd;
			process["pgrp"] = proc_info->pgrp;
			process["session"] = proc_info->session;
			process["nlwp"] = proc_info->nlwp;
			process["tgid"] = proc_info->tgid;
			process["tty"] = proc_info->tty; // 0
			process["euid"] = proc_info->euid;
			process["ruid"] = proc_info->ruid; // 0
			process["suid"] = proc_info->suid; // 0
			process["fuid"] = proc_info->fuid; // 1
			process["egid"] = proc_info->egid; // 0
			process["rgid"] = proc_info->rgid; // 0
			process["sgid"] = proc_info->sgid; // 0
			process["fgid"] = proc_info->fgid; // 0
			process["tpgid"] = proc_info->tpgid; // 0
			process["exit_signal"] = proc_info->exit_signal; // 0
			process["processor"] = proc_info->processor; // 2

			processes[processCounter] = process;

			freeproc(proc_info);
		}

		closeproc(proc);

		return processes;
	}
}
