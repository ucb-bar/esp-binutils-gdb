/* RISC-V opcode list
   Copyright (C) 2011-2017 Free Software Foundation, Inc.

   Contributed by Andrew Waterman (andrew@sifive.com).
   Based on MIPS target.

   This file is part of the GNU opcodes library.

   This library is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING3. If not,
   see <http://www.gnu.org/licenses/>.  */

#include "sysdep.h"
#include "opcode/riscv.h"
#include <stdio.h>

/* Register names used by gas and objdump.  */

const char * const riscv_gpr_names_numeric[NGPR] =
{
  "x0",   "x1",   "x2",   "x3",   "x4",   "x5",   "x6",   "x7",
  "x8",   "x9",   "x10",  "x11",  "x12",  "x13",  "x14",  "x15",
  "x16",  "x17",  "x18",  "x19",  "x20",  "x21",  "x22",  "x23",
  "x24",  "x25",  "x26",  "x27",  "x28",  "x29",  "x30",  "x31"
};

const char * const riscv_gpr_names_abi[NGPR] = {
  "zero", "ra", "sp",  "gp",  "tp", "t0",  "t1",  "t2",
  "s0",   "s1", "a0",  "a1",  "a2", "a3",  "a4",  "a5",
  "a6",   "a7", "s2",  "s3",  "s4", "s5",  "s6",  "s7",
  "s8",   "s9", "s10", "s11", "t3", "t4",  "t5",  "t6"
};

const char * const riscv_fpr_names_numeric[NFPR] =
{
  "f0",   "f1",   "f2",   "f3",   "f4",   "f5",   "f6",   "f7",
  "f8",   "f9",   "f10",  "f11",  "f12",  "f13",  "f14",  "f15",
  "f16",  "f17",  "f18",  "f19",  "f20",  "f21",  "f22",  "f23",
  "f24",  "f25",  "f26",  "f27",  "f28",  "f29",  "f30",  "f31"
};

const char * const riscv_fpr_names_abi[NFPR] = {
  "ft0", "ft1", "ft2",  "ft3",  "ft4", "ft5", "ft6",  "ft7",
  "fs0", "fs1", "fa0",  "fa1",  "fa2", "fa3", "fa4",  "fa5",
  "fa6", "fa7", "fs2",  "fs3",  "fs4", "fs5", "fs6",  "fs7",
  "fs8", "fs9", "fs10", "fs11", "ft8", "ft9", "ft10", "ft11"
};

const char * const riscv_vec_gpr_names[NVGPR] =
{
 "vv0",  "vv1",  "vv2",  "vv3",  "vv4",  "vv5",  "vv6",  "vv7",
 "vv8",  "vv9",  "vv10",  "vv11",  "vv12",  "vv13",  "vv14",  "vv15",
 "vv16",  "vv17",  "vv18",  "vv19",  "vv20",  "vv21",  "vv22",  "vv23",
 "vv24",  "vv25",  "vv26",  "vv27",  "vv28",  "vv29",  "vv30",  "vv31",
 "vv32",  "vv33",  "vv34",  "vv35",  "vv36",  "vv37",  "vv38",  "vv39",
 "vv40",  "vv41",  "vv42",  "vv43",  "vv44",  "vv45",  "vv46",  "vv47",
 "vv48",  "vv49",  "vv50",  "vv51",  "vv52",  "vv53",  "vv54",  "vv55",
 "vv56",  "vv57",  "vv58",  "vv59",  "vv60",  "vv61",  "vv62",  "vv63",
 "vv64",  "vv65",  "vv66",  "vv67",  "vv68",  "vv69",  "vv70",  "vv71",
 "vv72",  "vv73",  "vv74",  "vv75",  "vv76",  "vv77",  "vv78",  "vv79",
 "vv80",  "vv81",  "vv82",  "vv83",  "vv84",  "vv85",  "vv86",  "vv87",
 "vv88",  "vv89",  "vv90",  "vv91",  "vv92",  "vv93",  "vv94",  "vv95",
 "vv96",  "vv97",  "vv98",  "vv99", "vv100", "vv101", "vv102", "vv103",
 "vv104", "vv105", "vv106", "vv107", "vv108", "vv109", "vv110", "vv111",
 "vv112", "vv113", "vv114", "vv115", "vv116", "vv117", "vv118", "vv119",
 "vv120", "vv121", "vv122", "vv123", "vv124", "vv125", "vv126", "vv127",
 "vv128", "vv129", "vv130", "vv131", "vv132", "vv133", "vv134", "vv135",
 "vv136", "vv137", "vv138", "vv139", "vv140", "vv141", "vv142", "vv143",
 "vv144", "vv145", "vv146", "vv147", "vv148", "vv149", "vv150", "vv151",
 "vv152", "vv153", "vv154", "vv155", "vv156", "vv157", "vv158", "vv159",
 "vv160", "vv161", "vv162", "vv163", "vv164", "vv165", "vv166", "vv167",
 "vv168", "vv169", "vv170", "vv171", "vv172", "vv173", "vv174", "vv175",
 "vv176", "vv177", "vv178", "vv179", "vv180", "vv181", "vv182", "vv183",
 "vv184", "vv185", "vv186", "vv187", "vv188", "vv189", "vv190", "vv191",
 "vv192", "vv193", "vv194", "vv195", "vv196", "vv197", "vv198", "vv199",
 "vv200", "vv201", "vv202", "vv203", "vv204", "vv205", "vv206", "vv207",
 "vv208", "vv209", "vv210", "vv211", "vv212", "vv213", "vv214", "vv215",
 "vv216", "vv217", "vv218", "vv219", "vv220", "vv221", "vv222", "vv223",
 "vv224", "vv225", "vv226", "vv227", "vv228", "vv229", "vv230", "vv231",
 "vv232", "vv233", "vv234", "vv235", "vv236", "vv237", "vv238", "vv239",
 "vv240", "vv241", "vv242", "vv243", "vv244", "vv245", "vv246", "vv247",
 "vv248", "vv249", "vv250", "vv251", "vv252", "vv253", "vv254", "vv255"
};

const char * const riscv_vec_spr_names[NVSPR] =
{
 "vs0",  "vs1",  "vs2",  "vs3",  "vs4",  "vs5",  "vs6",  "vs7",
 "vs8",  "vs9",  "vs10",  "vs11",  "vs12",  "vs13",  "vs14",  "vs15",
 "vs16",  "vs17",  "vs18",  "vs19",  "vs20",  "vs21",  "vs22",  "vs23",
 "vs24",  "vs25",  "vs26",  "vs27",  "vs28",  "vs29",  "vs30",  "vs31",
 "vs32",  "vs33",  "vs34",  "vs35",  "vs36",  "vs37",  "vs38",  "vs39",
 "vs40",  "vs41",  "vs42",  "vs43",  "vs44",  "vs45",  "vs46",  "vs47",
 "vs48",  "vs49",  "vs50",  "vs51",  "vs52",  "vs53",  "vs54",  "vs55",
 "vs56",  "vs57",  "vs58",  "vs59",  "vs60",  "vs61",  "vs62",  "vs63",
 "vs64",  "vs65",  "vs66",  "vs67",  "vs68",  "vs69",  "vs70",  "vs71",
 "vs72",  "vs73",  "vs74",  "vs75",  "vs76",  "vs77",  "vs78",  "vs79",
 "vs80",  "vs81",  "vs82",  "vs83",  "vs84",  "vs85",  "vs86",  "vs87",
 "vs88",  "vs89",  "vs90",  "vs91",  "vs92",  "vs93",  "vs94",  "vs95",
 "vs96",  "vs97",  "vs98",  "vs99", "vs100", "vs101", "vs102", "vs103",
 "vs104", "vs105", "vs106", "vs107", "vs108", "vs109", "vs110", "vs111",
 "vs112", "vs113", "vs114", "vs115", "vs116", "vs117", "vs118", "vs119",
 "vs120", "vs121", "vs122", "vs123", "vs124", "vs125", "vs126", "vs127",
 "vs128", "vs129", "vs130", "vs131", "vs132", "vs133", "vs134", "vs135",
 "vs136", "vs137", "vs138", "vs139", "vs140", "vs141", "vs142", "vs143",
 "vs144", "vs145", "vs146", "vs147", "vs148", "vs149", "vs150", "vs151",
 "vs152", "vs153", "vs154", "vs155", "vs156", "vs157", "vs158", "vs159",
 "vs160", "vs161", "vs162", "vs163", "vs164", "vs165", "vs166", "vs167",
 "vs168", "vs169", "vs170", "vs171", "vs172", "vs173", "vs174", "vs175",
 "vs176", "vs177", "vs178", "vs179", "vs180", "vs181", "vs182", "vs183",
 "vs184", "vs185", "vs186", "vs187", "vs188", "vs189", "vs190", "vs191",
 "vs192", "vs193", "vs194", "vs195", "vs196", "vs197", "vs198", "vs199",
 "vs200", "vs201", "vs202", "vs203", "vs204", "vs205", "vs206", "vs207",
 "vs208", "vs209", "vs210", "vs211", "vs212", "vs213", "vs214", "vs215",
 "vs216", "vs217", "vs218", "vs219", "vs220", "vs221", "vs222", "vs223",
 "vs224", "vs225", "vs226", "vs227", "vs228", "vs229", "vs230", "vs231",
 "vs232", "vs233", "vs234", "vs235", "vs236", "vs237", "vs238", "vs239",
 "vs240", "vs241", "vs242", "vs243", "vs244", "vs245", "vs246", "vs247",
 "vs248", "vs249", "vs250", "vs251", "vs252", "vs253", "vs254", "vs255"
};

const char * const riscv_vec_apr_names[NVAPR] =
{
  "va0",   "va1",   "va2",   "va3",   "va4",   "va5",   "va6",   "va7",
  "va8",   "va9",   "va10",  "va11",  "va12",  "va13",  "va14",  "va15",
  "va16",  "va17",  "va18",  "va19",  "va20",  "va21",  "va22",  "va23",
  "va24",  "va25",  "va26",  "va27",  "va28",  "va29",  "va30",  "va31"
};

const char * const riscv_vec_ppr_names[NVPPR] =
{
  "vp0",   "vp1",   "vp2",   "vp3",   "vp4",   "vp5",   "vp6",   "vp7",
  "vp8",   "vp9",   "vp10",  "vp11",  "vp12",  "vp13",  "vp14",  "vp15"
};

/* The order of overloaded instructions matters.  Label arguments and
   register arguments look the same. Instructions that can have either
   for arguments must apear in the correct order in this table for the
   assembler to pick the right one. In other words, entries with
   immediate operands must apear after the same instruction with
   registers.

   Because of the lookup algorithm used, entries with the same opcode
   name must be contiguous.  */

#define MASK_RS1 (OP_MASK_RS1 << OP_SH_RS1)
#define MASK_RS2 (OP_MASK_RS2 << OP_SH_RS2)
#define MASK_RD (OP_MASK_RD << OP_SH_RD)
#define MASK_CRS2 (OP_MASK_CRS2 << OP_SH_CRS2)
#define MASK_IMM ENCODE_ITYPE_IMM (-1U)
#define MASK_RVC_IMM ENCODE_RVC_IMM (-1U)
#define MASK_UIMM ENCODE_UTYPE_IMM (-1U)
#define MASK_RM (OP_MASK_RM << OP_SH_RM)
#define MASK_PRED (OP_MASK_PRED << OP_SH_PRED)
#define MASK_SUCC (OP_MASK_SUCC << OP_SH_SUCC)
#define MASK_AQ (OP_MASK_AQ << OP_SH_AQ)
#define MASK_RL (OP_MASK_RL << OP_SH_RL)
#define MASK_AQRL (MASK_AQ | MASK_RL)

#define MASK_VRD (OP_MASK_VRD << OP_SH_VRD)
#define MASK_VRS1 ((insn_t)OP_MASK_VRS << OP_SH_VRS)
#define MASK_VRS2 ((insn_t)OP_MASK_VRT << OP_SH_VRT)
#define MASK_VS1 ((insn_t)OP_MASK_VS1 << OP_SH_VS1)
#define MASK_VIMM ENCODE_ITYPE_VIMM(-1U)
#define MASK_VRM ((insn_t)OP_MASK_VRM << OP_SH_VRM)
#define MASK_VAQ ((insn_t)OP_MASK_VAQ << OP_SH_VAQ)
#define MASK_VRL ((insn_t)OP_MASK_VRL << OP_SH_VRL)
#define MASK_VAQRL (MASK_VAQ | MASK_VRL)
#define MASK_VPRED ((insn_t)OP_MASK_VPRED << OP_SH_VPRED)
#define MASK_VN ((insn_t)OP_MASK_VN << OP_SH_VN)
#define MASK_VPREV (OP_MASK_VPREV << OP_SH_VPREV)
#define MASK_VSUCC (OP_MASK_VSUCC << OP_SH_VSUCC)

static int
match_opcode (const struct riscv_opcode *op, insn_t insn)
{
  return ((insn ^ op->match) & op->mask) == 0;
}

static int
match_never (const struct riscv_opcode *op ATTRIBUTE_UNUSED,
	     insn_t insn ATTRIBUTE_UNUSED)
{
  return 0;
}

static int
match_rs1_eq_rs2 (const struct riscv_opcode *op, insn_t insn)
{
  int rs1 = (insn & MASK_RS1) >> OP_SH_RS1;
  int rs2 = (insn & MASK_RS2) >> OP_SH_RS2;
  return match_opcode (op, insn) && rs1 == rs2;
}

static int
match_rd_nonzero (const struct riscv_opcode *op, insn_t insn)
{
  return match_opcode (op, insn) && ((insn & MASK_RD) != 0);
}

static int
match_c_add (const struct riscv_opcode *op, insn_t insn)
{
  return match_rd_nonzero (op, insn) && ((insn & MASK_CRS2) != 0);
}

/* We don't allow mv zero,X to become a c.mv hint, so we need a separate
   matching function for this.  */

static int
match_c_add_with_hint (const struct riscv_opcode *op, insn_t insn)
{
  return match_opcode (op, insn) && ((insn & MASK_CRS2) != 0);
}

static int
match_c_addi16sp (const struct riscv_opcode *op, insn_t insn)
{
  return (match_opcode (op, insn)
	  && (((insn & MASK_RD) >> OP_SH_RD) == 2)
	  && EXTRACT_RVC_ADDI16SP_IMM (insn) != 0);
}

static int
match_c_lui (const struct riscv_opcode *op, insn_t insn)
{
  return (match_rd_nonzero (op, insn)
	  && (((insn & MASK_RD) >> OP_SH_RD) != 2)
	  && EXTRACT_RVC_LUI_IMM (insn) != 0);
}

/* We don't allow lui zero,X to become a c.lui hint, so we need a separate
   matching function for this.  */

static int
match_c_lui_with_hint (const struct riscv_opcode *op, insn_t insn)
{
  return (match_opcode (op, insn)
	  && (((insn & MASK_RD) >> OP_SH_RD) != 2)
	  && EXTRACT_RVC_LUI_IMM (insn) != 0);
}

static int
match_c_addi4spn (const struct riscv_opcode *op, insn_t insn)
{
  return match_opcode (op, insn) && EXTRACT_RVC_ADDI4SPN_IMM (insn) != 0;
}

const struct riscv_opcode riscv_opcodes[] =
{
/* name,      isa,   operands, match, mask, match_func, pinfo.  */
{"unimp",     "C",   "",  0, 0xffffU,  match_opcode, 0 },
{"unimp",     "I",   "",  MATCH_CSRRW | (CSR_CYCLE << OP_SH_CSR), 0xffffffffU,  match_opcode, 0 }, /* csrw cycle, x0 */
{"ebreak",    "C",   "",  MATCH_C_EBREAK, MASK_C_EBREAK, match_opcode, INSN_ALIAS },
{"ebreak",    "I",   "",    MATCH_EBREAK, MASK_EBREAK, match_opcode, 0 },
{"sbreak",    "C",   "",  MATCH_C_EBREAK, MASK_C_EBREAK, match_opcode, INSN_ALIAS },
{"sbreak",    "I",   "",    MATCH_EBREAK, MASK_EBREAK, match_opcode, INSN_ALIAS },
{"ret",       "C",   "",  MATCH_C_JR | (X_RA << OP_SH_RD), MASK_C_JR | MASK_RD, match_opcode, INSN_ALIAS },
{"ret",       "I",   "",  MATCH_JALR | (X_RA << OP_SH_RS1), MASK_JALR | MASK_RD | MASK_RS1 | MASK_IMM, match_opcode, INSN_ALIAS },
{"jr",        "C",   "d",  MATCH_C_JR, MASK_C_JR, match_rd_nonzero, INSN_ALIAS },
{"jr",        "I",   "s",  MATCH_JALR, MASK_JALR | MASK_RD | MASK_IMM, match_opcode, INSN_ALIAS },
{"jr",        "I",   "o(s)",  MATCH_JALR, MASK_JALR | MASK_RD, match_opcode, INSN_ALIAS },
{"jr",        "I",   "s,j",  MATCH_JALR, MASK_JALR | MASK_RD, match_opcode, INSN_ALIAS },
{"jalr",      "C",   "d",  MATCH_C_JALR, MASK_C_JALR, match_rd_nonzero, INSN_ALIAS },
{"jalr",      "I",   "s",  MATCH_JALR | (X_RA << OP_SH_RD), MASK_JALR | MASK_RD | MASK_IMM, match_opcode, INSN_ALIAS },
{"jalr",      "I",   "o(s)",  MATCH_JALR | (X_RA << OP_SH_RD), MASK_JALR | MASK_RD, match_opcode, INSN_ALIAS },
{"jalr",      "I",   "s,j",  MATCH_JALR | (X_RA << OP_SH_RD), MASK_JALR | MASK_RD, match_opcode, INSN_ALIAS },
{"jalr",      "I",   "d,s",  MATCH_JALR, MASK_JALR | MASK_IMM, match_opcode, INSN_ALIAS },
{"jalr",      "I",   "d,o(s)",  MATCH_JALR, MASK_JALR, match_opcode, 0 },
{"jalr",      "I",   "d,s,j",  MATCH_JALR, MASK_JALR, match_opcode, 0 },
{"j",         "C",   "Ca",  MATCH_C_J, MASK_C_J, match_opcode, INSN_ALIAS },
{"j",         "I",   "a",  MATCH_JAL, MASK_JAL | MASK_RD, match_opcode, INSN_ALIAS },
{"jal",       "I",   "d,a",  MATCH_JAL, MASK_JAL, match_opcode, 0 },
{"jal",       "32C", "Ca",  MATCH_C_JAL, MASK_C_JAL, match_opcode, INSN_ALIAS },
{"jal",       "I",   "a",  MATCH_JAL | (X_RA << OP_SH_RD), MASK_JAL | MASK_RD, match_opcode, INSN_ALIAS },
{"call",      "I",   "d,c", (X_T1 << OP_SH_RS1), (int) M_CALL,  match_never, INSN_MACRO },
{"call",      "I",   "c", (X_RA << OP_SH_RS1) | (X_RA << OP_SH_RD), (int) M_CALL,  match_never, INSN_MACRO },
{"tail",      "I",   "c", (X_T1 << OP_SH_RS1), (int) M_CALL,  match_never, INSN_MACRO },
{"jump",      "I",   "c,s", 0, (int) M_CALL,  match_never, INSN_MACRO },
{"nop",       "C",   "",  MATCH_C_ADDI, 0xffff, match_opcode, INSN_ALIAS },
{"nop",       "I",   "",         MATCH_ADDI, MASK_ADDI | MASK_RD | MASK_RS1 | MASK_IMM, match_opcode, INSN_ALIAS },
{"lui",       "C",   "d,Cu",  MATCH_C_LUI, MASK_C_LUI, match_c_lui, INSN_ALIAS },
{"lui",       "I",   "d,u",  MATCH_LUI, MASK_LUI, match_opcode, 0 },
{"li",        "C",   "d,Cv",  MATCH_C_LUI, MASK_C_LUI, match_c_lui, INSN_ALIAS },
{"li",        "C",   "d,Co",  MATCH_C_LI, MASK_C_LI, match_rd_nonzero, INSN_ALIAS },
{"li",        "I",   "d,j",      MATCH_ADDI, MASK_ADDI | MASK_RS1, match_opcode, INSN_ALIAS }, /* addi */
{"li",        "I",   "d,I",  0,    (int) M_LI,  match_never, INSN_MACRO },
{"mv",        "C",   "d,CV",  MATCH_C_MV, MASK_C_MV, match_c_add, INSN_ALIAS },
{"mv",        "I",   "d,s",  MATCH_ADDI, MASK_ADDI | MASK_IMM, match_opcode, INSN_ALIAS },
{"move",      "C",   "d,CV",  MATCH_C_MV, MASK_C_MV, match_c_add, INSN_ALIAS },
{"move",      "I",   "d,s",  MATCH_ADDI, MASK_ADDI | MASK_IMM, match_opcode, INSN_ALIAS },
{"andi",      "C",   "Cs,Cw,Co",  MATCH_C_ANDI, MASK_C_ANDI, match_opcode, INSN_ALIAS },
{"andi",      "I",   "d,s,j",  MATCH_ANDI, MASK_ANDI, match_opcode, 0 },
{"and",       "C",   "Cs,Cw,Ct",  MATCH_C_AND, MASK_C_AND, match_opcode, INSN_ALIAS },
{"and",       "C",   "Cs,Ct,Cw",  MATCH_C_AND, MASK_C_AND, match_opcode, INSN_ALIAS },
{"and",       "C",   "Cs,Cw,Co",  MATCH_C_ANDI, MASK_C_ANDI, match_opcode, INSN_ALIAS },
{"and",       "I",   "d,s,t",  MATCH_AND, MASK_AND, match_opcode, 0 },
{"and",       "I",   "d,s,j",  MATCH_ANDI, MASK_ANDI, match_opcode, INSN_ALIAS },
{"beqz",      "C",   "Cs,Cp",  MATCH_C_BEQZ, MASK_C_BEQZ, match_opcode, INSN_ALIAS },
{"beqz",      "I",   "s,p",  MATCH_BEQ, MASK_BEQ | MASK_RS2, match_opcode, INSN_ALIAS },
{"beq",       "I",   "s,t,p",  MATCH_BEQ, MASK_BEQ, match_opcode, 0 },
{"blez",      "I",   "t,p",  MATCH_BGE, MASK_BGE | MASK_RS1, match_opcode, INSN_ALIAS },
{"bgez",      "I",   "s,p",  MATCH_BGE, MASK_BGE | MASK_RS2, match_opcode, INSN_ALIAS },
{"ble",       "I",   "t,s,p",  MATCH_BGE, MASK_BGE, match_opcode, INSN_ALIAS },
{"bleu",      "I",   "t,s,p",  MATCH_BGEU, MASK_BGEU, match_opcode, INSN_ALIAS },
{"bge",       "I",   "s,t,p",  MATCH_BGE, MASK_BGE, match_opcode, 0 },
{"bgeu",      "I",   "s,t,p",  MATCH_BGEU, MASK_BGEU, match_opcode, 0 },
{"bltz",      "I",   "s,p",  MATCH_BLT, MASK_BLT | MASK_RS2, match_opcode, INSN_ALIAS },
{"bgtz",      "I",   "t,p",  MATCH_BLT, MASK_BLT | MASK_RS1, match_opcode, INSN_ALIAS },
{"blt",       "I",   "s,t,p",  MATCH_BLT, MASK_BLT, match_opcode, 0 },
{"bltu",      "I",   "s,t,p",  MATCH_BLTU, MASK_BLTU, match_opcode, 0 },
{"bgt",       "I",   "t,s,p",  MATCH_BLT, MASK_BLT, match_opcode, INSN_ALIAS },
{"bgtu",      "I",   "t,s,p",  MATCH_BLTU, MASK_BLTU, match_opcode, INSN_ALIAS },
{"bnez",      "C",   "Cs,Cp",  MATCH_C_BNEZ, MASK_C_BNEZ, match_opcode, INSN_ALIAS },
{"bnez",      "I",   "s,p",  MATCH_BNE, MASK_BNE | MASK_RS2, match_opcode, INSN_ALIAS },
{"bne",       "I",   "s,t,p",  MATCH_BNE, MASK_BNE, match_opcode, 0 },
{"addi",      "C",   "Ct,Cc,CK", MATCH_C_ADDI4SPN, MASK_C_ADDI4SPN, match_c_addi4spn, INSN_ALIAS },
{"addi",      "C",   "d,CU,Cj",  MATCH_C_ADDI, MASK_C_ADDI, match_rd_nonzero, INSN_ALIAS },
{"addi",      "C",   "Cc,Cc,CL", MATCH_C_ADDI16SP, MASK_C_ADDI16SP, match_c_addi16sp, INSN_ALIAS },
{"addi",      "I",   "d,s,j",  MATCH_ADDI, MASK_ADDI, match_opcode, 0 },
{"add",       "C",   "d,CU,CV",  MATCH_C_ADD, MASK_C_ADD, match_c_add, INSN_ALIAS },
{"add",       "C",   "d,CV,CU",  MATCH_C_ADD, MASK_C_ADD, match_c_add, INSN_ALIAS },
{"add",       "C",   "d,CU,Co",  MATCH_C_ADDI, MASK_C_ADDI, match_rd_nonzero, INSN_ALIAS },
{"add",       "C",   "Ct,Cc,CK", MATCH_C_ADDI4SPN, MASK_C_ADDI4SPN, match_c_addi4spn, INSN_ALIAS },
{"add",       "C",   "Cc,Cc,CL", MATCH_C_ADDI16SP, MASK_C_ADDI16SP, match_c_addi16sp, INSN_ALIAS },
{"add",       "I",   "d,s,t",  MATCH_ADD, MASK_ADD, match_opcode, 0 },
/* This is used for TLS, where the fourth arg is %tprel_add, to get a reloc
   applied to an add instruction, for relaxation to use.  */
{"add",       "I",   "d,s,t,0",MATCH_ADD, MASK_ADD, match_opcode, 0 },
{"add",       "I",   "d,s,j",  MATCH_ADDI, MASK_ADDI, match_opcode, INSN_ALIAS },
{"la",        "I",   "d,A",  0,    (int) M_LA,  match_never, INSN_MACRO },
{"lla",       "I",   "d,A",  0,    (int) M_LLA,  match_never, INSN_MACRO },
{"la.tls.gd", "I",   "d,A",  0,    (int) M_LA_TLS_GD,  match_never, INSN_MACRO },
{"la.tls.ie", "I",   "d,A",  0,    (int) M_LA_TLS_IE,  match_never, INSN_MACRO },
{"neg",       "I",   "d,t",  MATCH_SUB, MASK_SUB | MASK_RS1, match_opcode, INSN_ALIAS }, /* sub 0 */
{"slli",      "C",   "d,CU,C>",  MATCH_C_SLLI, MASK_C_SLLI, match_rd_nonzero, INSN_ALIAS },
{"slli",      "I",   "d,s,>",   MATCH_SLLI, MASK_SLLI, match_opcode, 0 },
{"sll",       "C",   "d,CU,C>",  MATCH_C_SLLI, MASK_C_SLLI, match_rd_nonzero, INSN_ALIAS },
{"sll",       "I",   "d,s,t",   MATCH_SLL, MASK_SLL, match_opcode, 0 },
{"sll",       "I",   "d,s,>",   MATCH_SLLI, MASK_SLLI, match_opcode, INSN_ALIAS },
{"srli",      "C",   "Cs,Cw,C>",  MATCH_C_SRLI, MASK_C_SRLI, match_opcode, INSN_ALIAS },
{"srli",      "I",   "d,s,>",   MATCH_SRLI, MASK_SRLI, match_opcode, 0 },
{"srl",       "C",   "Cs,Cw,C>",  MATCH_C_SRLI, MASK_C_SRLI, match_opcode, INSN_ALIAS },
{"srl",       "I",   "d,s,t",   MATCH_SRL, MASK_SRL, match_opcode, 0 },
{"srl",       "I",   "d,s,>",   MATCH_SRLI, MASK_SRLI, match_opcode, INSN_ALIAS },
{"srai",      "C",   "Cs,Cw,C>",  MATCH_C_SRAI, MASK_C_SRAI, match_opcode, INSN_ALIAS },
{"srai",      "I",   "d,s,>",   MATCH_SRAI, MASK_SRAI, match_opcode, 0 },
{"sra",       "C",   "Cs,Cw,C>",  MATCH_C_SRAI, MASK_C_SRAI, match_opcode, INSN_ALIAS },
{"sra",       "I",   "d,s,t",   MATCH_SRA, MASK_SRA, match_opcode, 0 },
{"sra",       "I",   "d,s,>",   MATCH_SRAI, MASK_SRAI, match_opcode, INSN_ALIAS },
{"sub",       "C",   "Cs,Cw,Ct",  MATCH_C_SUB, MASK_C_SUB, match_opcode, INSN_ALIAS },
{"sub",       "I",   "d,s,t",  MATCH_SUB, MASK_SUB, match_opcode, 0 },
{"lb",        "I",   "d,o(s)",  MATCH_LB, MASK_LB, match_opcode, 0 },
{"lb",        "I",   "d,A",  0, (int) M_LB, match_never, INSN_MACRO },
{"lbu",       "I",   "d,o(s)",  MATCH_LBU, MASK_LBU, match_opcode, 0 },
{"lbu",       "I",   "d,A",  0, (int) M_LBU, match_never, INSN_MACRO },
{"lh",        "I",   "d,o(s)",  MATCH_LH, MASK_LH, match_opcode, 0 },
{"lh",        "I",   "d,A",  0, (int) M_LH, match_never, INSN_MACRO },
{"lhu",       "I",   "d,o(s)",  MATCH_LHU, MASK_LHU, match_opcode, 0 },
{"lhu",       "I",   "d,A",  0, (int) M_LHU, match_never, INSN_MACRO },
{"lw",        "C",   "d,Cm(Cc)",  MATCH_C_LWSP, MASK_C_LWSP, match_rd_nonzero, INSN_ALIAS },
{"lw",        "C",   "Ct,Ck(Cs)",  MATCH_C_LW, MASK_C_LW, match_opcode, INSN_ALIAS },
{"lw",        "I",   "d,o(s)",  MATCH_LW, MASK_LW, match_opcode, 0 },
{"lw",        "I",   "d,A",  0, (int) M_LW, match_never, INSN_MACRO },
{"not",       "I",   "d,s",  MATCH_XORI | MASK_IMM, MASK_XORI | MASK_IMM, match_opcode, INSN_ALIAS },
{"ori",       "I",   "d,s,j",  MATCH_ORI, MASK_ORI, match_opcode, 0 },
{"or",       "C",   "Cs,Cw,Ct",  MATCH_C_OR, MASK_C_OR, match_opcode, INSN_ALIAS },
{"or",       "C",   "Cs,Ct,Cw",  MATCH_C_OR, MASK_C_OR, match_opcode, INSN_ALIAS },
{"or",        "I",   "d,s,t",  MATCH_OR, MASK_OR, match_opcode, 0 },
{"or",        "I",   "d,s,j",  MATCH_ORI, MASK_ORI, match_opcode, INSN_ALIAS },
{"auipc",     "I",   "d,u",  MATCH_AUIPC, MASK_AUIPC, match_opcode, 0 },
{"seqz",      "I",   "d,s",  MATCH_SLTIU | ENCODE_ITYPE_IMM (1), MASK_SLTIU | MASK_IMM, match_opcode, INSN_ALIAS },
{"snez",      "I",   "d,t",  MATCH_SLTU, MASK_SLTU | MASK_RS1, match_opcode, INSN_ALIAS },
{"sltz",      "I",   "d,s",  MATCH_SLT, MASK_SLT | MASK_RS2, match_opcode, INSN_ALIAS },
{"sgtz",      "I",   "d,t",  MATCH_SLT, MASK_SLT | MASK_RS1, match_opcode, INSN_ALIAS },
{"slti",      "I",   "d,s,j",  MATCH_SLTI, MASK_SLTI, match_opcode, 0 },
{"slt",       "I",   "d,s,t",  MATCH_SLT, MASK_SLT, match_opcode, 0 },
{"slt",       "I",   "d,s,j",  MATCH_SLTI, MASK_SLTI, match_opcode, INSN_ALIAS },
{"sltiu",     "I",   "d,s,j",  MATCH_SLTIU, MASK_SLTIU, match_opcode, 0 },
{"sltu",      "I",   "d,s,t",  MATCH_SLTU, MASK_SLTU, match_opcode, 0 },
{"sltu",      "I",   "d,s,j",  MATCH_SLTIU, MASK_SLTIU, match_opcode, INSN_ALIAS },
{"sgt",       "I",   "d,t,s",  MATCH_SLT, MASK_SLT, match_opcode, INSN_ALIAS },
{"sgtu",      "I",   "d,t,s",  MATCH_SLTU, MASK_SLTU, match_opcode, INSN_ALIAS },
{"sb",        "I",   "t,q(s)",  MATCH_SB, MASK_SB, match_opcode, 0 },
{"sb",        "I",   "t,A,s",  0, (int) M_SB, match_never, INSN_MACRO },
{"sh",        "I",   "t,q(s)",  MATCH_SH, MASK_SH, match_opcode, 0 },
{"sh",        "I",   "t,A,s",  0, (int) M_SH, match_never, INSN_MACRO },
{"sw",        "C",   "CV,CM(Cc)",  MATCH_C_SWSP, MASK_C_SWSP, match_opcode, INSN_ALIAS },
{"sw",        "C",   "Ct,Ck(Cs)",  MATCH_C_SW, MASK_C_SW, match_opcode, INSN_ALIAS },
{"sw",        "I",   "t,q(s)",  MATCH_SW, MASK_SW, match_opcode, 0 },
{"sw",        "I",   "t,A,s",  0, (int) M_SW, match_never, INSN_MACRO },
{"fence",     "I",   "",  MATCH_FENCE | MASK_PRED | MASK_SUCC, MASK_FENCE | MASK_RD | MASK_RS1 | MASK_IMM, match_opcode, INSN_ALIAS },
{"fence",     "I",   "P,Q",  MATCH_FENCE, MASK_FENCE | MASK_RD | MASK_RS1 | (MASK_IMM & ~MASK_PRED & ~MASK_SUCC), match_opcode, 0 },
{"fence.i",   "I",   "",  MATCH_FENCE_I, MASK_FENCE | MASK_RD | MASK_RS1 | MASK_IMM, match_opcode, 0 },
{"rdcycle",   "I",   "d",  MATCH_RDCYCLE, MASK_RDCYCLE, match_opcode, INSN_ALIAS },
{"rdinstret", "I",   "d",  MATCH_RDINSTRET, MASK_RDINSTRET, match_opcode, INSN_ALIAS },
{"rdtime",    "I",   "d",  MATCH_RDTIME, MASK_RDTIME, match_opcode, INSN_ALIAS },
{"rdcycleh",  "32I", "d",  MATCH_RDCYCLEH, MASK_RDCYCLEH, match_opcode, INSN_ALIAS },
{"rdinstreth","32I", "d",  MATCH_RDINSTRETH, MASK_RDINSTRETH, match_opcode, INSN_ALIAS },
{"rdtimeh",   "32I", "d",  MATCH_RDTIMEH, MASK_RDTIMEH, match_opcode, INSN_ALIAS },
{"ecall",     "I",   "",    MATCH_SCALL, MASK_SCALL, match_opcode, 0 },
{"scall",     "I",   "",    MATCH_SCALL, MASK_SCALL, match_opcode, 0 },
{"xori",      "I",   "d,s,j",  MATCH_XORI, MASK_XORI, match_opcode, 0 },
{"xor",       "C",   "Cs,Cw,Ct",  MATCH_C_XOR, MASK_C_XOR, match_opcode, INSN_ALIAS },
{"xor",       "C",   "Cs,Ct,Cw",  MATCH_C_XOR, MASK_C_XOR, match_opcode, INSN_ALIAS },
{"xor",       "I",   "d,s,t",  MATCH_XOR, MASK_XOR, match_opcode, 0 },
{"xor",       "I",   "d,s,j",  MATCH_XORI, MASK_XORI, match_opcode, INSN_ALIAS },
{"lwu",       "64I", "d,o(s)",  MATCH_LWU, MASK_LWU, match_opcode, 0 },
{"lwu",       "64I", "d,A",  0, (int) M_LWU, match_never, INSN_MACRO },
{"ld",        "64C", "d,Cn(Cc)",  MATCH_C_LDSP, MASK_C_LDSP, match_rd_nonzero, INSN_ALIAS },
{"ld",        "64C", "Ct,Cl(Cs)",  MATCH_C_LD, MASK_C_LD, match_opcode, INSN_ALIAS },
{"ld",        "64I", "d,o(s)", MATCH_LD, MASK_LD, match_opcode, 0 },
{"ld",        "64I", "d,A",  0, (int) M_LD, match_never, INSN_MACRO },
{"sd",        "64C", "CV,CN(Cc)",  MATCH_C_SDSP, MASK_C_SDSP, match_opcode, INSN_ALIAS },
{"sd",        "64C", "Ct,Cl(Cs)",  MATCH_C_SD, MASK_C_SD, match_opcode, INSN_ALIAS },
{"sd",        "64I", "t,q(s)",  MATCH_SD, MASK_SD, match_opcode, 0 },
{"sd",        "64I", "t,A,s",  0, (int) M_SD, match_never, INSN_MACRO },
{"sext.w",    "64C", "d,CU",  MATCH_C_ADDIW, MASK_C_ADDIW | MASK_RVC_IMM, match_rd_nonzero, INSN_ALIAS },
{"sext.w",    "64I", "d,s",  MATCH_ADDIW, MASK_ADDIW | MASK_IMM, match_opcode, INSN_ALIAS },
{"addiw",     "64C", "d,CU,Co",  MATCH_C_ADDIW, MASK_C_ADDIW, match_rd_nonzero, INSN_ALIAS },
{"addiw",     "64I", "d,s,j",  MATCH_ADDIW, MASK_ADDIW, match_opcode, 0 },
{"addw",      "64C", "Cs,Cw,Ct",  MATCH_C_ADDW, MASK_C_ADDW, match_opcode, INSN_ALIAS },
{"addw",      "64C", "Cs,Ct,Cw",  MATCH_C_ADDW, MASK_C_ADDW, match_opcode, INSN_ALIAS },
{"addw",      "64C", "d,CU,Co",  MATCH_C_ADDIW, MASK_C_ADDIW, match_rd_nonzero, INSN_ALIAS },
{"addw",      "64I", "d,s,t",  MATCH_ADDW, MASK_ADDW, match_opcode, 0 },
{"addw",      "64I", "d,s,j",  MATCH_ADDIW, MASK_ADDIW, match_opcode, INSN_ALIAS },
{"negw",      "64I", "d,t",  MATCH_SUBW, MASK_SUBW | MASK_RS1, match_opcode, INSN_ALIAS }, /* sub 0 */
{"slliw",     "64I", "d,s,<",   MATCH_SLLIW, MASK_SLLIW, match_opcode, 0 },
{"sllw",      "64I", "d,s,t",   MATCH_SLLW, MASK_SLLW, match_opcode, 0 },
{"sllw",      "64I", "d,s,<",   MATCH_SLLIW, MASK_SLLIW, match_opcode, INSN_ALIAS },
{"srliw",     "64I", "d,s,<",   MATCH_SRLIW, MASK_SRLIW, match_opcode, 0 },
{"srlw",      "64I", "d,s,t",   MATCH_SRLW, MASK_SRLW, match_opcode, 0 },
{"srlw",      "64I", "d,s,<",   MATCH_SRLIW, MASK_SRLIW, match_opcode, INSN_ALIAS },
{"sraiw",     "64I", "d,s,<",   MATCH_SRAIW, MASK_SRAIW, match_opcode, 0 },
{"sraw",      "64I", "d,s,t",   MATCH_SRAW, MASK_SRAW, match_opcode, 0 },
{"sraw",      "64I", "d,s,<",   MATCH_SRAIW, MASK_SRAIW, match_opcode, INSN_ALIAS },
{"subw",      "64C", "Cs,Cw,Ct",  MATCH_C_SUBW, MASK_C_SUBW, match_opcode, INSN_ALIAS },
{"subw",      "64I", "d,s,t",  MATCH_SUBW, MASK_SUBW, match_opcode, 0 },

/* Atomic memory operation instruction subset */
{"lr.w",         "A",   "d,0(s)",    MATCH_LR_W, MASK_LR_W | MASK_AQRL, match_opcode, 0 },
{"sc.w",         "A",   "d,t,0(s)",  MATCH_SC_W, MASK_SC_W | MASK_AQRL, match_opcode, 0 },
{"amoadd.w",     "A",   "d,t,0(s)",  MATCH_AMOADD_W, MASK_AMOADD_W | MASK_AQRL, match_opcode, 0 },
{"amoswap.w",    "A",   "d,t,0(s)",  MATCH_AMOSWAP_W, MASK_AMOSWAP_W | MASK_AQRL, match_opcode, 0 },
{"amoand.w",     "A",   "d,t,0(s)",  MATCH_AMOAND_W, MASK_AMOAND_W | MASK_AQRL, match_opcode, 0 },
{"amoor.w",      "A",   "d,t,0(s)",  MATCH_AMOOR_W, MASK_AMOOR_W | MASK_AQRL, match_opcode, 0 },
{"amoxor.w",     "A",   "d,t,0(s)",  MATCH_AMOXOR_W, MASK_AMOXOR_W | MASK_AQRL, match_opcode, 0 },
{"amomax.w",     "A",   "d,t,0(s)",  MATCH_AMOMAX_W, MASK_AMOMAX_W | MASK_AQRL, match_opcode, 0 },
{"amomaxu.w",    "A",   "d,t,0(s)",  MATCH_AMOMAXU_W, MASK_AMOMAXU_W | MASK_AQRL, match_opcode, 0 },
{"amomin.w",     "A",   "d,t,0(s)",  MATCH_AMOMIN_W, MASK_AMOMIN_W | MASK_AQRL, match_opcode, 0 },
{"amominu.w",    "A",   "d,t,0(s)",  MATCH_AMOMINU_W, MASK_AMOMINU_W | MASK_AQRL, match_opcode, 0 },
{"lr.w.aq",      "A",   "d,0(s)",    MATCH_LR_W | MASK_AQ, MASK_LR_W | MASK_AQRL, match_opcode, 0 },
{"sc.w.aq",      "A",   "d,t,0(s)",  MATCH_SC_W | MASK_AQ, MASK_SC_W | MASK_AQRL, match_opcode, 0 },
{"amoadd.w.aq",  "A",   "d,t,0(s)",  MATCH_AMOADD_W | MASK_AQ, MASK_AMOADD_W | MASK_AQRL, match_opcode, 0 },
{"amoswap.w.aq", "A",   "d,t,0(s)",  MATCH_AMOSWAP_W | MASK_AQ, MASK_AMOSWAP_W | MASK_AQRL, match_opcode, 0 },
{"amoand.w.aq",  "A",   "d,t,0(s)",  MATCH_AMOAND_W | MASK_AQ, MASK_AMOAND_W | MASK_AQRL, match_opcode, 0 },
{"amoor.w.aq",   "A",   "d,t,0(s)",  MATCH_AMOOR_W | MASK_AQ, MASK_AMOOR_W | MASK_AQRL, match_opcode, 0 },
{"amoxor.w.aq",  "A",   "d,t,0(s)",  MATCH_AMOXOR_W | MASK_AQ, MASK_AMOXOR_W | MASK_AQRL, match_opcode, 0 },
{"amomax.w.aq",  "A",   "d,t,0(s)",  MATCH_AMOMAX_W | MASK_AQ, MASK_AMOMAX_W | MASK_AQRL, match_opcode, 0 },
{"amomaxu.w.aq", "A",   "d,t,0(s)",  MATCH_AMOMAXU_W | MASK_AQ, MASK_AMOMAXU_W | MASK_AQRL, match_opcode, 0 },
{"amomin.w.aq",  "A",   "d,t,0(s)",  MATCH_AMOMIN_W | MASK_AQ, MASK_AMOMIN_W | MASK_AQRL, match_opcode, 0 },
{"amominu.w.aq", "A",   "d,t,0(s)",  MATCH_AMOMINU_W | MASK_AQ, MASK_AMOMINU_W | MASK_AQRL, match_opcode, 0 },
{"lr.w.rl",      "A",   "d,0(s)",    MATCH_LR_W | MASK_RL, MASK_LR_W | MASK_AQRL, match_opcode, 0 },
{"sc.w.rl",      "A",   "d,t,0(s)",  MATCH_SC_W | MASK_RL, MASK_SC_W | MASK_AQRL, match_opcode, 0 },
{"amoadd.w.rl",  "A",   "d,t,0(s)",  MATCH_AMOADD_W | MASK_RL, MASK_AMOADD_W | MASK_AQRL, match_opcode, 0 },
{"amoswap.w.rl", "A",   "d,t,0(s)",  MATCH_AMOSWAP_W | MASK_RL, MASK_AMOSWAP_W | MASK_AQRL, match_opcode, 0 },
{"amoand.w.rl",  "A",   "d,t,0(s)",  MATCH_AMOAND_W | MASK_RL, MASK_AMOAND_W | MASK_AQRL, match_opcode, 0 },
{"amoor.w.rl",   "A",   "d,t,0(s)",  MATCH_AMOOR_W | MASK_RL, MASK_AMOOR_W | MASK_AQRL, match_opcode, 0 },
{"amoxor.w.rl",  "A",   "d,t,0(s)",  MATCH_AMOXOR_W | MASK_RL, MASK_AMOXOR_W | MASK_AQRL, match_opcode, 0 },
{"amomax.w.rl",  "A",   "d,t,0(s)",  MATCH_AMOMAX_W | MASK_RL, MASK_AMOMAX_W | MASK_AQRL, match_opcode, 0 },
{"amomaxu.w.rl", "A",   "d,t,0(s)",  MATCH_AMOMAXU_W | MASK_RL, MASK_AMOMAXU_W | MASK_AQRL, match_opcode, 0 },
{"amomin.w.rl",  "A",   "d,t,0(s)",  MATCH_AMOMIN_W | MASK_RL, MASK_AMOMIN_W | MASK_AQRL, match_opcode, 0 },
{"amominu.w.rl", "A",   "d,t,0(s)",  MATCH_AMOMINU_W | MASK_RL, MASK_AMOMINU_W | MASK_AQRL, match_opcode, 0 },
{"lr.w.aqrl",    "A",   "d,0(s)",    MATCH_LR_W | MASK_AQRL, MASK_LR_W | MASK_AQRL, match_opcode, 0 },
{"sc.w.aqrl",    "A",   "d,t,0(s)",  MATCH_SC_W | MASK_AQRL, MASK_SC_W | MASK_AQRL, match_opcode, 0 },
{"amoadd.w.aqrl",  "A",   "d,t,0(s)",  MATCH_AMOADD_W | MASK_AQRL, MASK_AMOADD_W | MASK_AQRL, match_opcode, 0 },
{"amoswap.w.aqrl", "A",   "d,t,0(s)",  MATCH_AMOSWAP_W | MASK_AQRL, MASK_AMOSWAP_W | MASK_AQRL, match_opcode, 0 },
{"amoand.w.aqrl",  "A",   "d,t,0(s)",  MATCH_AMOAND_W | MASK_AQRL, MASK_AMOAND_W | MASK_AQRL, match_opcode, 0 },
{"amoor.w.aqrl",   "A",   "d,t,0(s)",  MATCH_AMOOR_W | MASK_AQRL, MASK_AMOOR_W | MASK_AQRL, match_opcode, 0 },
{"amoxor.w.aqrl",  "A",   "d,t,0(s)",  MATCH_AMOXOR_W | MASK_AQRL, MASK_AMOXOR_W | MASK_AQRL, match_opcode, 0 },
{"amomax.w.aqrl",  "A",   "d,t,0(s)",  MATCH_AMOMAX_W | MASK_AQRL, MASK_AMOMAX_W | MASK_AQRL, match_opcode, 0 },
{"amomaxu.w.aqrl", "A",   "d,t,0(s)",  MATCH_AMOMAXU_W | MASK_AQRL, MASK_AMOMAXU_W | MASK_AQRL, match_opcode, 0 },
{"amomin.w.aqrl",  "A",   "d,t,0(s)",  MATCH_AMOMIN_W | MASK_AQRL, MASK_AMOMIN_W | MASK_AQRL, match_opcode, 0 },
{"amominu.w.aqrl", "A",   "d,t,0(s)",  MATCH_AMOMINU_W | MASK_AQRL, MASK_AMOMINU_W | MASK_AQRL, match_opcode, 0 },
{"lr.d",         "64A", "d,0(s)",    MATCH_LR_D, MASK_LR_D | MASK_AQRL, match_opcode, 0 },
{"sc.d",         "64A", "d,t,0(s)",  MATCH_SC_D, MASK_SC_D | MASK_AQRL, match_opcode, 0 },
{"amoadd.d",     "64A", "d,t,0(s)",  MATCH_AMOADD_D, MASK_AMOADD_D | MASK_AQRL, match_opcode, 0 },
{"amoswap.d",    "64A", "d,t,0(s)",  MATCH_AMOSWAP_D, MASK_AMOSWAP_D | MASK_AQRL, match_opcode, 0 },
{"amoand.d",     "64A", "d,t,0(s)",  MATCH_AMOAND_D, MASK_AMOAND_D | MASK_AQRL, match_opcode, 0 },
{"amoor.d",      "64A", "d,t,0(s)",  MATCH_AMOOR_D, MASK_AMOOR_D | MASK_AQRL, match_opcode, 0 },
{"amoxor.d",     "64A", "d,t,0(s)",  MATCH_AMOXOR_D, MASK_AMOXOR_D | MASK_AQRL, match_opcode, 0 },
{"amomax.d",     "64A", "d,t,0(s)",  MATCH_AMOMAX_D, MASK_AMOMAX_D | MASK_AQRL, match_opcode, 0 },
{"amomaxu.d",    "64A", "d,t,0(s)",  MATCH_AMOMAXU_D, MASK_AMOMAXU_D | MASK_AQRL, match_opcode, 0 },
{"amomin.d",     "64A", "d,t,0(s)",  MATCH_AMOMIN_D, MASK_AMOMIN_D | MASK_AQRL, match_opcode, 0 },
{"amominu.d",    "64A", "d,t,0(s)",  MATCH_AMOMINU_D, MASK_AMOMINU_D | MASK_AQRL, match_opcode, 0 },
{"lr.d.aq",      "64A", "d,0(s)",    MATCH_LR_D | MASK_AQ, MASK_LR_D | MASK_AQRL, match_opcode, 0 },
{"sc.d.aq",      "64A", "d,t,0(s)",  MATCH_SC_D | MASK_AQ, MASK_SC_D | MASK_AQRL, match_opcode, 0 },
{"amoadd.d.aq",  "64A", "d,t,0(s)",  MATCH_AMOADD_D | MASK_AQ, MASK_AMOADD_D | MASK_AQRL, match_opcode, 0 },
{"amoswap.d.aq", "64A", "d,t,0(s)",  MATCH_AMOSWAP_D | MASK_AQ, MASK_AMOSWAP_D | MASK_AQRL, match_opcode, 0 },
{"amoand.d.aq",  "64A", "d,t,0(s)",  MATCH_AMOAND_D | MASK_AQ, MASK_AMOAND_D | MASK_AQRL, match_opcode, 0 },
{"amoor.d.aq",   "64A", "d,t,0(s)",  MATCH_AMOOR_D | MASK_AQ, MASK_AMOOR_D | MASK_AQRL, match_opcode, 0 },
{"amoxor.d.aq",  "64A", "d,t,0(s)",  MATCH_AMOXOR_D | MASK_AQ, MASK_AMOXOR_D | MASK_AQRL, match_opcode, 0 },
{"amomax.d.aq",  "64A", "d,t,0(s)",  MATCH_AMOMAX_D | MASK_AQ, MASK_AMOMAX_D | MASK_AQRL, match_opcode, 0 },
{"amomaxu.d.aq", "64A", "d,t,0(s)",  MATCH_AMOMAXU_D | MASK_AQ, MASK_AMOMAXU_D | MASK_AQRL, match_opcode, 0 },
{"amomin.d.aq",  "64A", "d,t,0(s)",  MATCH_AMOMIN_D | MASK_AQ, MASK_AMOMIN_D | MASK_AQRL, match_opcode, 0 },
{"amominu.d.aq", "64A", "d,t,0(s)",  MATCH_AMOMINU_D | MASK_AQ, MASK_AMOMINU_D | MASK_AQRL, match_opcode, 0 },
{"lr.d.rl",      "64A", "d,0(s)",    MATCH_LR_D | MASK_RL, MASK_LR_D | MASK_AQRL, match_opcode, 0 },
{"sc.d.rl",      "64A", "d,t,0(s)",  MATCH_SC_D | MASK_RL, MASK_SC_D | MASK_AQRL, match_opcode, 0 },
{"amoadd.d.rl",  "64A", "d,t,0(s)",  MATCH_AMOADD_D | MASK_RL, MASK_AMOADD_D | MASK_AQRL, match_opcode, 0 },
{"amoswap.d.rl", "64A", "d,t,0(s)",  MATCH_AMOSWAP_D | MASK_RL, MASK_AMOSWAP_D | MASK_AQRL, match_opcode, 0 },
{"amoand.d.rl",  "64A", "d,t,0(s)",  MATCH_AMOAND_D | MASK_RL, MASK_AMOAND_D | MASK_AQRL, match_opcode, 0 },
{"amoor.d.rl",   "64A", "d,t,0(s)",  MATCH_AMOOR_D | MASK_RL, MASK_AMOOR_D | MASK_AQRL, match_opcode, 0 },
{"amoxor.d.rl",  "64A", "d,t,0(s)",  MATCH_AMOXOR_D | MASK_RL, MASK_AMOXOR_D | MASK_AQRL, match_opcode, 0 },
{"amomax.d.rl",  "64A", "d,t,0(s)",  MATCH_AMOMAX_D | MASK_RL, MASK_AMOMAX_D | MASK_AQRL, match_opcode, 0 },
{"amomaxu.d.rl", "64A", "d,t,0(s)",  MATCH_AMOMAXU_D | MASK_RL, MASK_AMOMAXU_D | MASK_AQRL, match_opcode, 0 },
{"amomin.d.rl",  "64A", "d,t,0(s)",  MATCH_AMOMIN_D | MASK_RL, MASK_AMOMIN_D | MASK_AQRL, match_opcode, 0 },
{"amominu.d.rl", "64A", "d,t,0(s)",  MATCH_AMOMINU_D | MASK_RL, MASK_AMOMINU_D | MASK_AQRL, match_opcode, 0 },
{"lr.d.aqrl",    "64A", "d,0(s)",    MATCH_LR_D | MASK_AQRL, MASK_LR_D | MASK_AQRL, match_opcode, 0 },
{"sc.d.aqrl",    "64A", "d,t,0(s)",  MATCH_SC_D | MASK_AQRL, MASK_SC_D | MASK_AQRL, match_opcode, 0 },
{"amoadd.d.aqrl",  "64A", "d,t,0(s)",  MATCH_AMOADD_D | MASK_AQRL, MASK_AMOADD_D | MASK_AQRL, match_opcode, 0 },
{"amoswap.d.aqrl", "64A", "d,t,0(s)",  MATCH_AMOSWAP_D | MASK_AQRL, MASK_AMOSWAP_D | MASK_AQRL, match_opcode, 0 },
{"amoand.d.aqrl",  "64A", "d,t,0(s)",  MATCH_AMOAND_D | MASK_AQRL, MASK_AMOAND_D | MASK_AQRL, match_opcode, 0 },
{"amoor.d.aqrl",   "64A", "d,t,0(s)",  MATCH_AMOOR_D | MASK_AQRL, MASK_AMOOR_D | MASK_AQRL, match_opcode, 0 },
{"amoxor.d.aqrl",  "64A", "d,t,0(s)",  MATCH_AMOXOR_D | MASK_AQRL, MASK_AMOXOR_D | MASK_AQRL, match_opcode, 0 },
{"amomax.d.aqrl",  "64A", "d,t,0(s)",  MATCH_AMOMAX_D | MASK_AQRL, MASK_AMOMAX_D | MASK_AQRL, match_opcode, 0 },
{"amomaxu.d.aqrl", "64A", "d,t,0(s)",  MATCH_AMOMAXU_D | MASK_AQRL, MASK_AMOMAXU_D | MASK_AQRL, match_opcode, 0 },
{"amomin.d.aqrl",  "64A", "d,t,0(s)",  MATCH_AMOMIN_D | MASK_AQRL, MASK_AMOMIN_D | MASK_AQRL, match_opcode, 0 },
{"amominu.d.aqrl", "64A", "d,t,0(s)",  MATCH_AMOMINU_D | MASK_AQRL, MASK_AMOMINU_D | MASK_AQRL, match_opcode, 0 },

/* Multiply/Divide instruction subset */
{"mul",       "M",   "d,s,t",  MATCH_MUL, MASK_MUL, match_opcode, 0 },
{"mulh",      "M",   "d,s,t",  MATCH_MULH, MASK_MULH, match_opcode, 0 },
{"mulhu",     "M",   "d,s,t",  MATCH_MULHU, MASK_MULHU, match_opcode, 0 },
{"mulhsu",    "M",   "d,s,t",  MATCH_MULHSU, MASK_MULHSU, match_opcode, 0 },
{"div",       "M",   "d,s,t",  MATCH_DIV, MASK_DIV, match_opcode, 0 },
{"divu",      "M",   "d,s,t",  MATCH_DIVU, MASK_DIVU, match_opcode, 0 },
{"rem",       "M",   "d,s,t",  MATCH_REM, MASK_REM, match_opcode, 0 },
{"remu",      "M",   "d,s,t",  MATCH_REMU, MASK_REMU, match_opcode, 0 },
{"mulw",      "64M", "d,s,t",  MATCH_MULW, MASK_MULW, match_opcode, 0 },
{"divw",      "64M", "d,s,t",  MATCH_DIVW, MASK_DIVW, match_opcode, 0 },
{"divuw",     "64M", "d,s,t",  MATCH_DIVUW, MASK_DIVUW, match_opcode, 0 },
{"remw",      "64M", "d,s,t",  MATCH_REMW, MASK_REMW, match_opcode, 0 },
{"remuw",     "64M", "d,s,t",  MATCH_REMUW, MASK_REMUW, match_opcode, 0 },

/* Single-precision floating-point instruction subset */
{"frsr",      "F",   "d",  MATCH_FRCSR, MASK_FRCSR, match_opcode, 0 },
{"fssr",      "F",   "s",  MATCH_FSCSR, MASK_FSCSR | MASK_RD, match_opcode, 0 },
{"fssr",      "F",   "d,s",  MATCH_FSCSR, MASK_FSCSR, match_opcode, 0 },
{"frcsr",     "F",   "d",  MATCH_FRCSR, MASK_FRCSR, match_opcode, 0 },
{"fscsr",     "F",   "s",  MATCH_FSCSR, MASK_FSCSR | MASK_RD, match_opcode, 0 },
{"fscsr",     "F",   "d,s",  MATCH_FSCSR, MASK_FSCSR, match_opcode, 0 },
{"frrm",      "F",   "d",  MATCH_FRRM, MASK_FRRM, match_opcode, 0 },
{"fsrm",      "F",   "s",  MATCH_FSRM, MASK_FSRM | MASK_RD, match_opcode, 0 },
{"fsrm",      "F",   "d,s",  MATCH_FSRM, MASK_FSRM, match_opcode, 0 },
{"fsrmi",     "F",   "d,Z",  MATCH_FSRMI, MASK_FSRMI, match_opcode, 0 },
{"fsrmi",     "F",   "Z",  MATCH_FSRMI, MASK_FSRMI | MASK_RD, match_opcode, 0 },
{"frflags",   "F",   "d",  MATCH_FRFLAGS, MASK_FRFLAGS, match_opcode, 0 },
{"fsflags",   "F",   "s",  MATCH_FSFLAGS, MASK_FSFLAGS | MASK_RD, match_opcode, 0 },
{"fsflags",   "F",   "d,s",  MATCH_FSFLAGS, MASK_FSFLAGS, match_opcode, 0 },
{"fsflagsi",  "F",   "d,Z",  MATCH_FSFLAGSI, MASK_FSFLAGSI, match_opcode, 0 },
{"fsflagsi",  "F",   "Z",  MATCH_FSFLAGSI, MASK_FSFLAGSI | MASK_RD, match_opcode, 0 },
{"flw",       "32C", "D,Cm(Cc)",  MATCH_C_FLWSP, MASK_C_FLWSP, match_opcode, INSN_ALIAS },
{"flw",       "32C", "CD,Ck(Cs)",  MATCH_C_FLW, MASK_C_FLW, match_opcode, INSN_ALIAS },
{"flw",       "F",   "D,o(s)",  MATCH_FLW, MASK_FLW, match_opcode, 0 },
{"flw",       "F",   "D,A,s",  0, (int) M_FLW, match_never, INSN_MACRO },
{"fsw",       "32C", "CT,CM(Cc)",  MATCH_C_FSWSP, MASK_C_FSWSP, match_opcode, INSN_ALIAS },
{"fsw",       "32C", "CD,Ck(Cs)",  MATCH_C_FSW, MASK_C_FSW, match_opcode, INSN_ALIAS },
{"fsw",       "F",   "T,q(s)",  MATCH_FSW, MASK_FSW, match_opcode, 0 },
{"fsw",       "F",   "T,A,s",  0, (int) M_FSW, match_never, INSN_MACRO },

{"fmv.x.w",   "F",   "d,S",  MATCH_FMV_X_S, MASK_FMV_X_S, match_opcode, 0 },
{"fmv.w.x",   "F",   "D,s",  MATCH_FMV_S_X, MASK_FMV_S_X, match_opcode, 0 },

{"fmv.x.s",   "F",   "d,S",  MATCH_FMV_X_S, MASK_FMV_X_S, match_opcode, 0 },
{"fmv.s.x",   "F",   "D,s",  MATCH_FMV_S_X, MASK_FMV_S_X, match_opcode, 0 },

{"fmv.s",     "F",   "D,U",  MATCH_FSGNJ_S, MASK_FSGNJ_S, match_rs1_eq_rs2, INSN_ALIAS },
{"fneg.s",    "F",   "D,U",  MATCH_FSGNJN_S, MASK_FSGNJN_S, match_rs1_eq_rs2, INSN_ALIAS },
{"fabs.s",    "F",   "D,U",  MATCH_FSGNJX_S, MASK_FSGNJX_S, match_rs1_eq_rs2, INSN_ALIAS },
{"fsgnj.s",   "F",   "D,S,T",  MATCH_FSGNJ_S, MASK_FSGNJ_S, match_opcode, 0 },
{"fsgnjn.s",  "F",   "D,S,T",  MATCH_FSGNJN_S, MASK_FSGNJN_S, match_opcode, 0 },
{"fsgnjx.s",  "F",   "D,S,T",  MATCH_FSGNJX_S, MASK_FSGNJX_S, match_opcode, 0 },
{"fadd.s",    "F",   "D,S,T",  MATCH_FADD_S | MASK_RM, MASK_FADD_S | MASK_RM, match_opcode, 0 },
{"fadd.s",    "F",   "D,S,T,m",  MATCH_FADD_S, MASK_FADD_S, match_opcode, 0 },
{"fsub.s",    "F",   "D,S,T",  MATCH_FSUB_S | MASK_RM, MASK_FSUB_S | MASK_RM, match_opcode, 0 },
{"fsub.s",    "F",   "D,S,T,m",  MATCH_FSUB_S, MASK_FSUB_S, match_opcode, 0 },
{"fmul.s",    "F",   "D,S,T",  MATCH_FMUL_S | MASK_RM, MASK_FMUL_S | MASK_RM, match_opcode, 0 },
{"fmul.s",    "F",   "D,S,T,m",  MATCH_FMUL_S, MASK_FMUL_S, match_opcode, 0 },
{"fdiv.s",    "F",   "D,S,T",  MATCH_FDIV_S | MASK_RM, MASK_FDIV_S | MASK_RM, match_opcode, 0 },
{"fdiv.s",    "F",   "D,S,T,m",  MATCH_FDIV_S, MASK_FDIV_S, match_opcode, 0 },
{"fsqrt.s",   "F",   "D,S",  MATCH_FSQRT_S | MASK_RM, MASK_FSQRT_S | MASK_RM, match_opcode, 0 },
{"fsqrt.s",   "F",   "D,S,m",  MATCH_FSQRT_S, MASK_FSQRT_S, match_opcode, 0 },
{"fmin.s",    "F",   "D,S,T",  MATCH_FMIN_S, MASK_FMIN_S, match_opcode, 0 },
{"fmax.s",    "F",   "D,S,T",  MATCH_FMAX_S, MASK_FMAX_S, match_opcode, 0 },
{"fmadd.s",   "F",   "D,S,T,R",  MATCH_FMADD_S | MASK_RM, MASK_FMADD_S | MASK_RM, match_opcode, 0 },
{"fmadd.s",   "F",   "D,S,T,R,m",  MATCH_FMADD_S, MASK_FMADD_S, match_opcode, 0 },
{"fnmadd.s",  "F",   "D,S,T,R",  MATCH_FNMADD_S | MASK_RM, MASK_FNMADD_S | MASK_RM, match_opcode, 0 },
{"fnmadd.s",  "F",   "D,S,T,R,m",  MATCH_FNMADD_S, MASK_FNMADD_S, match_opcode, 0 },
{"fmsub.s",   "F",   "D,S,T,R",  MATCH_FMSUB_S | MASK_RM, MASK_FMSUB_S | MASK_RM, match_opcode, 0 },
{"fmsub.s",   "F",   "D,S,T,R,m",  MATCH_FMSUB_S, MASK_FMSUB_S, match_opcode, 0 },
{"fnmsub.s",  "F",   "D,S,T,R",  MATCH_FNMSUB_S | MASK_RM, MASK_FNMSUB_S | MASK_RM, match_opcode, 0 },
{"fnmsub.s",  "F",   "D,S,T,R,m",  MATCH_FNMSUB_S, MASK_FNMSUB_S, match_opcode, 0 },
{"fcvt.w.s",  "F",   "d,S",  MATCH_FCVT_W_S | MASK_RM, MASK_FCVT_W_S | MASK_RM, match_opcode, 0 },
{"fcvt.w.s",  "F",   "d,S,m",  MATCH_FCVT_W_S, MASK_FCVT_W_S, match_opcode, 0 },
{"fcvt.wu.s", "F",   "d,S",  MATCH_FCVT_WU_S | MASK_RM, MASK_FCVT_WU_S | MASK_RM, match_opcode, 0 },
{"fcvt.wu.s", "F",   "d,S,m",  MATCH_FCVT_WU_S, MASK_FCVT_WU_S, match_opcode, 0 },
{"fcvt.s.w",  "F",   "D,s",  MATCH_FCVT_S_W | MASK_RM, MASK_FCVT_S_W | MASK_RM, match_opcode, 0 },
{"fcvt.s.w",  "F",   "D,s,m",  MATCH_FCVT_S_W, MASK_FCVT_S_W, match_opcode, 0 },
{"fcvt.s.wu", "F",   "D,s",  MATCH_FCVT_S_WU | MASK_RM, MASK_FCVT_S_W | MASK_RM, match_opcode, 0 },
{"fcvt.s.wu", "F",   "D,s,m",  MATCH_FCVT_S_WU, MASK_FCVT_S_WU, match_opcode, 0 },
{"fclass.s",  "F",   "d,S",  MATCH_FCLASS_S, MASK_FCLASS_S, match_opcode, 0 },
{"feq.s",     "F",   "d,S,T",    MATCH_FEQ_S, MASK_FEQ_S, match_opcode, 0 },
{"flt.s",     "F",   "d,S,T",    MATCH_FLT_S, MASK_FLT_S, match_opcode, 0 },
{"fle.s",     "F",   "d,S,T",    MATCH_FLE_S, MASK_FLE_S, match_opcode, 0 },
{"fgt.s",     "F",   "d,T,S",    MATCH_FLT_S, MASK_FLT_S, match_opcode, 0 },
{"fge.s",     "F",   "d,T,S",    MATCH_FLE_S, MASK_FLE_S, match_opcode, 0 },
{"fcvt.l.s",  "64F", "d,S",  MATCH_FCVT_L_S | MASK_RM, MASK_FCVT_L_S | MASK_RM, match_opcode, 0 },
{"fcvt.l.s",  "64F", "d,S,m",  MATCH_FCVT_L_S, MASK_FCVT_L_S, match_opcode, 0 },
{"fcvt.lu.s", "64F", "d,S",  MATCH_FCVT_LU_S | MASK_RM, MASK_FCVT_LU_S | MASK_RM, match_opcode, 0 },
{"fcvt.lu.s", "64F", "d,S,m",  MATCH_FCVT_LU_S, MASK_FCVT_LU_S, match_opcode, 0 },
{"fcvt.s.l",  "64F", "D,s",  MATCH_FCVT_S_L | MASK_RM, MASK_FCVT_S_L | MASK_RM, match_opcode, 0 },
{"fcvt.s.l",  "64F", "D,s,m",  MATCH_FCVT_S_L, MASK_FCVT_S_L, match_opcode, 0 },
{"fcvt.s.lu", "64F", "D,s",  MATCH_FCVT_S_LU | MASK_RM, MASK_FCVT_S_L | MASK_RM, match_opcode, 0 },
{"fcvt.s.lu", "64F", "D,s,m",  MATCH_FCVT_S_LU, MASK_FCVT_S_LU, match_opcode, 0 },

/* Double-precision floating-point instruction subset */
{"fld",       "C",   "D,Cn(Cc)",  MATCH_C_FLDSP, MASK_C_FLDSP, match_opcode, INSN_ALIAS },
{"fld",       "C",   "CD,Cl(Cs)",  MATCH_C_FLD, MASK_C_FLD, match_opcode, INSN_ALIAS },
{"fld",       "D",   "D,o(s)",  MATCH_FLD, MASK_FLD, match_opcode, 0 },
{"fld",       "D",   "D,A,s",  0, (int) M_FLD, match_never, INSN_MACRO },
{"fsd",       "C",   "CT,CN(Cc)",  MATCH_C_FSDSP, MASK_C_FSDSP, match_opcode, INSN_ALIAS },
{"fsd",       "C",   "CD,Cl(Cs)",  MATCH_C_FSD, MASK_C_FSD, match_opcode, INSN_ALIAS },
{"fsd",       "D",   "T,q(s)",  MATCH_FSD, MASK_FSD, match_opcode, 0 },
{"fsd",       "D",   "T,A,s",  0, (int) M_FSD, match_never, INSN_MACRO },
{"fmv.d",     "D",   "D,U",  MATCH_FSGNJ_D, MASK_FSGNJ_D, match_rs1_eq_rs2, INSN_ALIAS },
{"fneg.d",    "D",   "D,U",  MATCH_FSGNJN_D, MASK_FSGNJN_D, match_rs1_eq_rs2, INSN_ALIAS },
{"fabs.d",    "D",   "D,U",  MATCH_FSGNJX_D, MASK_FSGNJX_D, match_rs1_eq_rs2, INSN_ALIAS },
{"fsgnj.d",   "D",   "D,S,T",  MATCH_FSGNJ_D, MASK_FSGNJ_D, match_opcode, 0 },
{"fsgnjn.d",  "D",   "D,S,T",  MATCH_FSGNJN_D, MASK_FSGNJN_D, match_opcode, 0 },
{"fsgnjx.d",  "D",   "D,S,T",  MATCH_FSGNJX_D, MASK_FSGNJX_D, match_opcode, 0 },
{"fadd.d",    "D",   "D,S,T",  MATCH_FADD_D | MASK_RM, MASK_FADD_D | MASK_RM, match_opcode, 0 },
{"fadd.d",    "D",   "D,S,T,m",  MATCH_FADD_D, MASK_FADD_D, match_opcode, 0 },
{"fsub.d",    "D",   "D,S,T",  MATCH_FSUB_D | MASK_RM, MASK_FSUB_D | MASK_RM, match_opcode, 0 },
{"fsub.d",    "D",   "D,S,T,m",  MATCH_FSUB_D, MASK_FSUB_D, match_opcode, 0 },
{"fmul.d",    "D",   "D,S,T",  MATCH_FMUL_D | MASK_RM, MASK_FMUL_D | MASK_RM, match_opcode, 0 },
{"fmul.d",    "D",   "D,S,T,m",  MATCH_FMUL_D, MASK_FMUL_D, match_opcode, 0 },
{"fdiv.d",    "D",   "D,S,T",  MATCH_FDIV_D | MASK_RM, MASK_FDIV_D | MASK_RM, match_opcode, 0 },
{"fdiv.d",    "D",   "D,S,T,m",  MATCH_FDIV_D, MASK_FDIV_D, match_opcode, 0 },
{"fsqrt.d",   "D",   "D,S",  MATCH_FSQRT_D | MASK_RM, MASK_FSQRT_D | MASK_RM, match_opcode, 0 },
{"fsqrt.d",   "D",   "D,S,m",  MATCH_FSQRT_D, MASK_FSQRT_D, match_opcode, 0 },
{"fmin.d",    "D",   "D,S,T",  MATCH_FMIN_D, MASK_FMIN_D, match_opcode, 0 },
{"fmax.d",    "D",   "D,S,T",  MATCH_FMAX_D, MASK_FMAX_D, match_opcode, 0 },
{"fmadd.d",   "D",   "D,S,T,R",  MATCH_FMADD_D | MASK_RM, MASK_FMADD_D | MASK_RM, match_opcode, 0 },
{"fmadd.d",   "D",   "D,S,T,R,m",  MATCH_FMADD_D, MASK_FMADD_D, match_opcode, 0 },
{"fnmadd.d",  "D",   "D,S,T,R",  MATCH_FNMADD_D | MASK_RM, MASK_FNMADD_D | MASK_RM, match_opcode, 0 },
{"fnmadd.d",  "D",   "D,S,T,R,m",  MATCH_FNMADD_D, MASK_FNMADD_D, match_opcode, 0 },
{"fmsub.d",   "D",   "D,S,T,R",  MATCH_FMSUB_D | MASK_RM, MASK_FMSUB_D | MASK_RM, match_opcode, 0 },
{"fmsub.d",   "D",   "D,S,T,R,m",  MATCH_FMSUB_D, MASK_FMSUB_D, match_opcode, 0 },
{"fnmsub.d",  "D",   "D,S,T,R",  MATCH_FNMSUB_D | MASK_RM, MASK_FNMSUB_D | MASK_RM, match_opcode, 0 },
{"fnmsub.d",  "D",   "D,S,T,R,m",  MATCH_FNMSUB_D, MASK_FNMSUB_D, match_opcode, 0 },
{"fcvt.w.d",  "D",   "d,S",  MATCH_FCVT_W_D | MASK_RM, MASK_FCVT_W_D | MASK_RM, match_opcode, 0 },
{"fcvt.w.d",  "D",   "d,S,m",  MATCH_FCVT_W_D, MASK_FCVT_W_D, match_opcode, 0 },
{"fcvt.wu.d", "D",   "d,S",  MATCH_FCVT_WU_D | MASK_RM, MASK_FCVT_WU_D | MASK_RM, match_opcode, 0 },
{"fcvt.wu.d", "D",   "d,S,m",  MATCH_FCVT_WU_D, MASK_FCVT_WU_D, match_opcode, 0 },
{"fcvt.d.w",  "D",   "D,s",  MATCH_FCVT_D_W, MASK_FCVT_D_W | MASK_RM, match_opcode, 0 },
{"fcvt.d.wu", "D",   "D,s",  MATCH_FCVT_D_WU, MASK_FCVT_D_WU | MASK_RM, match_opcode, 0 },
{"fcvt.d.s",  "D",   "D,S",  MATCH_FCVT_D_S, MASK_FCVT_D_S | MASK_RM, match_opcode, 0 },
{"fcvt.s.d",  "D",   "D,S",  MATCH_FCVT_S_D | MASK_RM, MASK_FCVT_S_D | MASK_RM, match_opcode, 0 },
{"fcvt.s.d",  "D",   "D,S,m",  MATCH_FCVT_S_D, MASK_FCVT_S_D, match_opcode, 0 },
{"fclass.d",  "D",   "d,S",  MATCH_FCLASS_D, MASK_FCLASS_D, match_opcode, 0 },
{"feq.d",     "D",   "d,S,T",    MATCH_FEQ_D, MASK_FEQ_D, match_opcode, 0 },
{"flt.d",     "D",   "d,S,T",    MATCH_FLT_D, MASK_FLT_D, match_opcode, 0 },
{"fle.d",     "D",   "d,S,T",    MATCH_FLE_D, MASK_FLE_D, match_opcode, 0 },
{"fgt.d",     "D",   "d,T,S",    MATCH_FLT_D, MASK_FLT_D, match_opcode, 0 },
{"fge.d",     "D",   "d,T,S",    MATCH_FLE_D, MASK_FLE_D, match_opcode, 0 },
{"fmv.x.d",   "64D", "d,S",  MATCH_FMV_X_D, MASK_FMV_X_D, match_opcode, 0 },
{"fmv.d.x",   "64D", "D,s",  MATCH_FMV_D_X, MASK_FMV_D_X, match_opcode, 0 },
{"fcvt.l.d",  "64D", "d,S",  MATCH_FCVT_L_D | MASK_RM, MASK_FCVT_L_D | MASK_RM, match_opcode, 0 },
{"fcvt.l.d",  "64D", "d,S,m",  MATCH_FCVT_L_D, MASK_FCVT_L_D, match_opcode, 0 },
{"fcvt.lu.d", "64D", "d,S",  MATCH_FCVT_LU_D | MASK_RM, MASK_FCVT_LU_D | MASK_RM, match_opcode, 0 },
{"fcvt.lu.d", "64D", "d,S,m",  MATCH_FCVT_LU_D, MASK_FCVT_LU_D, match_opcode, 0 },
{"fcvt.d.l",  "64D", "D,s",  MATCH_FCVT_D_L | MASK_RM, MASK_FCVT_D_L | MASK_RM, match_opcode, 0 },
{"fcvt.d.l",  "64D", "D,s,m",  MATCH_FCVT_D_L, MASK_FCVT_D_L, match_opcode, 0 },
{"fcvt.d.lu", "64D", "D,s",  MATCH_FCVT_D_LU | MASK_RM, MASK_FCVT_D_L | MASK_RM, match_opcode, 0 },
{"fcvt.d.lu", "64D", "D,s,m",  MATCH_FCVT_D_LU, MASK_FCVT_D_LU, match_opcode, 0 },

/* Quad-precision floating-point instruction subset */
{"flq",       "Q",   "D,o(s)",  MATCH_FLQ, MASK_FLQ, match_opcode, 0 },
{"flq",       "Q",   "D,A,s",  0, (int) M_FLQ, match_never, INSN_MACRO },
{"fsq",       "Q",   "T,q(s)",  MATCH_FSQ, MASK_FSQ, match_opcode, 0 },
{"fsq",       "Q",   "T,A,s",  0, (int) M_FSQ, match_never, INSN_MACRO },
{"fmv.q",     "Q",   "D,U",  MATCH_FSGNJ_Q, MASK_FSGNJ_Q, match_rs1_eq_rs2, INSN_ALIAS },
{"fneg.q",    "Q",   "D,U",  MATCH_FSGNJN_Q, MASK_FSGNJN_Q, match_rs1_eq_rs2, INSN_ALIAS },
{"fabs.q",    "Q",   "D,U",  MATCH_FSGNJX_Q, MASK_FSGNJX_Q, match_rs1_eq_rs2, INSN_ALIAS },
{"fsgnj.q",   "Q",   "D,S,T",  MATCH_FSGNJ_Q, MASK_FSGNJ_Q, match_opcode, 0 },
{"fsgnjn.q",  "Q",   "D,S,T",  MATCH_FSGNJN_Q, MASK_FSGNJN_Q, match_opcode, 0 },
{"fsgnjx.q",  "Q",   "D,S,T",  MATCH_FSGNJX_Q, MASK_FSGNJX_Q, match_opcode, 0 },
{"fadd.q",    "Q",   "D,S,T",  MATCH_FADD_Q | MASK_RM, MASK_FADD_Q | MASK_RM, match_opcode, 0 },
{"fadd.q",    "Q",   "D,S,T,m",  MATCH_FADD_Q, MASK_FADD_Q, match_opcode, 0 },
{"fsub.q",    "Q",   "D,S,T",  MATCH_FSUB_Q | MASK_RM, MASK_FSUB_Q | MASK_RM, match_opcode, 0 },
{"fsub.q",    "Q",   "D,S,T,m",  MATCH_FSUB_Q, MASK_FSUB_Q, match_opcode, 0 },
{"fmul.q",    "Q",   "D,S,T",  MATCH_FMUL_Q | MASK_RM, MASK_FMUL_Q | MASK_RM, match_opcode, 0 },
{"fmul.q",    "Q",   "D,S,T,m",  MATCH_FMUL_Q, MASK_FMUL_Q, match_opcode, 0 },
{"fdiv.q",    "Q",   "D,S,T",  MATCH_FDIV_Q | MASK_RM, MASK_FDIV_Q | MASK_RM, match_opcode, 0 },
{"fdiv.q",    "Q",   "D,S,T,m",  MATCH_FDIV_Q, MASK_FDIV_Q, match_opcode, 0 },
{"fsqrt.q",   "Q",   "D,S",  MATCH_FSQRT_Q | MASK_RM, MASK_FSQRT_Q | MASK_RM, match_opcode, 0 },
{"fsqrt.q",   "Q",   "D,S,m",  MATCH_FSQRT_Q, MASK_FSQRT_Q, match_opcode, 0 },
{"fmin.q",    "Q",   "D,S,T",  MATCH_FMIN_Q, MASK_FMIN_Q, match_opcode, 0 },
{"fmax.q",    "Q",   "D,S,T",  MATCH_FMAX_Q, MASK_FMAX_Q, match_opcode, 0 },
{"fmadd.q",   "Q",   "D,S,T,R",  MATCH_FMADD_Q | MASK_RM, MASK_FMADD_Q | MASK_RM, match_opcode, 0 },
{"fmadd.q",   "Q",   "D,S,T,R,m",  MATCH_FMADD_Q, MASK_FMADD_Q, match_opcode, 0 },
{"fnmadd.q",  "Q",   "D,S,T,R",  MATCH_FNMADD_Q | MASK_RM, MASK_FNMADD_Q | MASK_RM, match_opcode, 0 },
{"fnmadd.q",  "Q",   "D,S,T,R,m",  MATCH_FNMADD_Q, MASK_FNMADD_Q, match_opcode, 0 },
{"fmsub.q",   "Q",   "D,S,T,R",  MATCH_FMSUB_Q | MASK_RM, MASK_FMSUB_Q | MASK_RM, match_opcode, 0 },
{"fmsub.q",   "Q",   "D,S,T,R,m",  MATCH_FMSUB_Q, MASK_FMSUB_Q, match_opcode, 0 },
{"fnmsub.q",  "Q",   "D,S,T,R",  MATCH_FNMSUB_Q | MASK_RM, MASK_FNMSUB_Q | MASK_RM, match_opcode, 0 },
{"fnmsub.q",  "Q",   "D,S,T,R,m",  MATCH_FNMSUB_Q, MASK_FNMSUB_Q, match_opcode, 0 },
{"fcvt.w.q",  "Q",   "d,S",  MATCH_FCVT_W_Q | MASK_RM, MASK_FCVT_W_Q | MASK_RM, match_opcode, 0 },
{"fcvt.w.q",  "Q",   "d,S,m",  MATCH_FCVT_W_Q, MASK_FCVT_W_Q, match_opcode, 0 },
{"fcvt.wu.q", "Q",   "d,S",  MATCH_FCVT_WU_Q | MASK_RM, MASK_FCVT_WU_Q | MASK_RM, match_opcode, 0 },
{"fcvt.wu.q", "Q",   "d,S,m",  MATCH_FCVT_WU_Q, MASK_FCVT_WU_Q, match_opcode, 0 },
{"fcvt.q.w",  "Q",   "D,s",  MATCH_FCVT_Q_W, MASK_FCVT_Q_W | MASK_RM, match_opcode, 0 },
{"fcvt.q.wu", "Q",   "D,s",  MATCH_FCVT_Q_WU, MASK_FCVT_Q_WU | MASK_RM, match_opcode, 0 },
{"fcvt.q.s",  "Q",   "D,S",  MATCH_FCVT_Q_S, MASK_FCVT_Q_S | MASK_RM, match_opcode, 0 },
{"fcvt.q.d",  "Q",   "D,S",  MATCH_FCVT_Q_D, MASK_FCVT_Q_D | MASK_RM, match_opcode, 0 },
{"fcvt.s.q",  "Q",   "D,S",  MATCH_FCVT_S_Q | MASK_RM, MASK_FCVT_S_Q | MASK_RM, match_opcode, 0 },
{"fcvt.s.q",  "Q",   "D,S,m",  MATCH_FCVT_S_Q, MASK_FCVT_S_Q, match_opcode, 0 },
{"fcvt.d.q",  "Q",   "D,S",  MATCH_FCVT_D_Q | MASK_RM, MASK_FCVT_D_Q | MASK_RM, match_opcode, 0 },
{"fcvt.d.q",  "Q",   "D,S,m",  MATCH_FCVT_D_Q, MASK_FCVT_D_Q, match_opcode, 0 },
{"fclass.q",  "Q",   "d,S",  MATCH_FCLASS_Q, MASK_FCLASS_Q, match_opcode, 0 },
{"feq.q",     "Q",   "d,S,T",    MATCH_FEQ_Q, MASK_FEQ_Q, match_opcode, 0 },
{"flt.q",     "Q",   "d,S,T",    MATCH_FLT_Q, MASK_FLT_Q, match_opcode, 0 },
{"fle.q",     "Q",   "d,S,T",    MATCH_FLE_Q, MASK_FLE_Q, match_opcode, 0 },
{"fgt.q",     "Q",   "d,T,S",    MATCH_FLT_Q, MASK_FLT_Q, match_opcode, 0 },
{"fge.q",     "Q",   "d,T,S",    MATCH_FLE_Q, MASK_FLE_Q, match_opcode, 0 },
{"fmv.x.q",   "64Q", "d,S",  MATCH_FMV_X_Q, MASK_FMV_X_Q, match_opcode, 0 },
{"fmv.q.x",   "64Q", "D,s",  MATCH_FMV_Q_X, MASK_FMV_Q_X, match_opcode, 0 },
{"fcvt.l.q",  "64Q", "d,S",  MATCH_FCVT_L_Q | MASK_RM, MASK_FCVT_L_Q | MASK_RM, match_opcode, 0 },
{"fcvt.l.q",  "64Q", "d,S,m",  MATCH_FCVT_L_Q, MASK_FCVT_L_Q, match_opcode, 0 },
{"fcvt.lu.q", "64Q", "d,S",  MATCH_FCVT_LU_Q | MASK_RM, MASK_FCVT_LU_Q | MASK_RM, match_opcode, 0 },
{"fcvt.lu.q", "64Q", "d,S,m",  MATCH_FCVT_LU_Q, MASK_FCVT_LU_Q, match_opcode, 0 },
{"fcvt.q.l",  "64Q", "D,s",  MATCH_FCVT_Q_L | MASK_RM, MASK_FCVT_Q_L | MASK_RM, match_opcode, 0 },
{"fcvt.q.l",  "64Q", "D,s,m",  MATCH_FCVT_Q_L, MASK_FCVT_Q_L, match_opcode, 0 },
{"fcvt.q.lu", "64Q", "D,s",  MATCH_FCVT_Q_LU | MASK_RM, MASK_FCVT_Q_L | MASK_RM, match_opcode, 0 },
{"fcvt.q.lu", "64Q", "D,s,m",  MATCH_FCVT_Q_LU, MASK_FCVT_Q_LU, match_opcode, 0 },

/* Compressed instructions.  */
{"c.ebreak",  "C",   "",  MATCH_C_EBREAK, MASK_C_EBREAK, match_opcode, 0 },
{"c.jr",      "C",   "d",  MATCH_C_JR, MASK_C_JR, match_rd_nonzero, 0 },
{"c.jalr",    "C",   "d",  MATCH_C_JALR, MASK_C_JALR, match_rd_nonzero, 0 },
{"c.j",       "C",   "Ca",  MATCH_C_J, MASK_C_J, match_opcode, 0 },
{"c.jal",     "32C", "Ca",  MATCH_C_JAL, MASK_C_JAL, match_opcode, 0 },
{"c.beqz",    "C",   "Cs,Cp",  MATCH_C_BEQZ, MASK_C_BEQZ, match_opcode, 0 },
{"c.bnez",    "C",   "Cs,Cp",  MATCH_C_BNEZ, MASK_C_BNEZ, match_opcode, 0 },
{"c.lwsp",    "C",   "d,Cm(Cc)",  MATCH_C_LWSP, MASK_C_LWSP, match_rd_nonzero, 0 },
{"c.lw",      "C",   "Ct,Ck(Cs)",  MATCH_C_LW, MASK_C_LW, match_opcode, 0 },
{"c.swsp",    "C",   "CV,CM(Cc)",  MATCH_C_SWSP, MASK_C_SWSP, match_opcode, 0 },
{"c.sw",      "C",   "Ct,Ck(Cs)",  MATCH_C_SW, MASK_C_SW, match_opcode, 0 },
{"c.nop",     "C",   "",  MATCH_C_ADDI, 0xffff, match_opcode, INSN_ALIAS },
{"c.nop",     "C",   "Cj",  MATCH_C_ADDI, MASK_C_ADDI | MASK_RD, match_opcode, INSN_ALIAS },
{"c.mv",      "C",   "d,CV",  MATCH_C_MV, MASK_C_MV, match_c_add_with_hint, 0 },
{"c.lui",     "C",   "d,Cu",  MATCH_C_LUI, MASK_C_LUI, match_c_lui_with_hint, 0 },
{"c.li",      "C",   "d,Co",  MATCH_C_LI, MASK_C_LI, match_opcode, 0 },
{"c.addi4spn","C",   "Ct,Cc,CK", MATCH_C_ADDI4SPN, MASK_C_ADDI4SPN, match_c_addi4spn, 0 },
{"c.addi16sp","C",   "Cc,CL", MATCH_C_ADDI16SP, MASK_C_ADDI16SP, match_c_addi16sp, 0 },
{"c.addi",    "C",   "d,Co",  MATCH_C_ADDI, MASK_C_ADDI, match_opcode, 0 },
{"c.add",     "C",   "d,CV",  MATCH_C_ADD, MASK_C_ADD, match_c_add_with_hint, 0 },
{"c.sub",     "C",   "Cs,Ct",  MATCH_C_SUB, MASK_C_SUB, match_opcode, 0 },
{"c.and",     "C",   "Cs,Ct",  MATCH_C_AND, MASK_C_AND, match_opcode, 0 },
{"c.or",      "C",   "Cs,Ct",  MATCH_C_OR, MASK_C_OR, match_opcode, 0 },
{"c.xor",     "C",   "Cs,Ct",  MATCH_C_XOR, MASK_C_XOR, match_opcode, 0 },
{"c.slli",    "C",   "d,C>",  MATCH_C_SLLI, MASK_C_SLLI, match_opcode, 0 },
{"c.srli",    "C",   "Cs,C>",  MATCH_C_SRLI, MASK_C_SRLI, match_opcode, 0 },
{"c.srai",    "C",   "Cs,C>",  MATCH_C_SRAI, MASK_C_SRAI, match_opcode, 0 },
{"c.andi",    "C",   "Cs,Co",  MATCH_C_ANDI, MASK_C_ANDI, match_opcode, 0 },
{"c.addiw",   "64C", "d,Co",  MATCH_C_ADDIW, MASK_C_ADDIW, match_rd_nonzero, 0 },
{"c.addw",    "64C", "Cs,Ct",  MATCH_C_ADDW, MASK_C_ADDW, match_opcode, 0 },
{"c.subw",    "64C", "Cs,Ct",  MATCH_C_SUBW, MASK_C_SUBW, match_opcode, 0 },
{"c.ldsp",    "64C", "d,Cn(Cc)",  MATCH_C_LDSP, MASK_C_LDSP, match_rd_nonzero, 0 },
{"c.ld",      "64C", "Ct,Cl(Cs)",  MATCH_C_LD, MASK_C_LD, match_opcode, 0 },
{"c.sdsp",    "64C", "CV,CN(Cc)",  MATCH_C_SDSP, MASK_C_SDSP, match_opcode, 0 },
{"c.sd",      "64C", "Ct,Cl(Cs)",  MATCH_C_SD, MASK_C_SD, match_opcode, 0 },
{"c.fldsp",   "C",   "D,Cn(Cc)",  MATCH_C_FLDSP, MASK_C_FLDSP, match_opcode, 0 },
{"c.fld",     "C",   "CD,Cl(Cs)",  MATCH_C_FLD, MASK_C_FLD, match_opcode, 0 },
{"c.fsdsp",   "C",   "CT,CN(Cc)",  MATCH_C_FSDSP, MASK_C_FSDSP, match_opcode, 0 },
{"c.fsd",     "C",   "CD,Cl(Cs)",  MATCH_C_FSD, MASK_C_FSD, match_opcode, 0 },
{"c.flwsp",   "32C", "D,Cm(Cc)",  MATCH_C_FLWSP, MASK_C_FLWSP, match_opcode, 0 },
{"c.flw",     "32C", "CD,Ck(Cs)",  MATCH_C_FLW, MASK_C_FLW, match_opcode, 0 },
{"c.fswsp",   "32C", "CT,CM(Cc)",  MATCH_C_FSWSP, MASK_C_FSWSP, match_opcode, 0 },
{"c.fsw",     "32C", "CD,Ck(Cs)",  MATCH_C_FSW, MASK_C_FSW, match_opcode, 0 },

/* Supervisor instructions */
{"csrr",      "I",   "d,E",  MATCH_CSRRS, MASK_CSRRS | MASK_RS1, match_opcode, INSN_ALIAS },
{"csrwi",     "I",   "E,Z",  MATCH_CSRRWI, MASK_CSRRWI | MASK_RD, match_opcode, INSN_ALIAS },
{"csrsi",     "I",   "E,Z",  MATCH_CSRRSI, MASK_CSRRSI | MASK_RD, match_opcode, INSN_ALIAS },
{"csrci",     "I",   "E,Z",  MATCH_CSRRCI, MASK_CSRRCI | MASK_RD, match_opcode, INSN_ALIAS },
{"csrw",      "I",   "E,s",  MATCH_CSRRW, MASK_CSRRW | MASK_RD, match_opcode, INSN_ALIAS },
{"csrw",      "I",   "E,Z",  MATCH_CSRRWI, MASK_CSRRWI | MASK_RD, match_opcode, INSN_ALIAS },
{"csrs",      "I",   "E,s",  MATCH_CSRRS, MASK_CSRRS | MASK_RD, match_opcode, INSN_ALIAS },
{"csrs",      "I",   "E,Z",  MATCH_CSRRSI, MASK_CSRRSI | MASK_RD, match_opcode, INSN_ALIAS },
{"csrc",      "I",   "E,s",  MATCH_CSRRC, MASK_CSRRC | MASK_RD, match_opcode, INSN_ALIAS },
{"csrc",      "I",   "E,Z",  MATCH_CSRRCI, MASK_CSRRCI | MASK_RD, match_opcode, INSN_ALIAS },
{"csrrwi",    "I",   "d,E,Z",  MATCH_CSRRWI, MASK_CSRRWI, match_opcode, 0 },
{"csrrsi",    "I",   "d,E,Z",  MATCH_CSRRSI, MASK_CSRRSI, match_opcode, 0 },
{"csrrci",    "I",   "d,E,Z",  MATCH_CSRRCI, MASK_CSRRCI, match_opcode, 0 },
{"csrrw",     "I",   "d,E,s",  MATCH_CSRRW, MASK_CSRRW, match_opcode, 0 },
{"csrrw",     "I",   "d,E,Z",  MATCH_CSRRWI, MASK_CSRRWI, match_opcode, INSN_ALIAS },
{"csrrs",     "I",   "d,E,s",  MATCH_CSRRS, MASK_CSRRS, match_opcode, 0 },
{"csrrs",     "I",   "d,E,Z",  MATCH_CSRRSI, MASK_CSRRSI, match_opcode, INSN_ALIAS },
{"csrrc",     "I",   "d,E,s",  MATCH_CSRRC, MASK_CSRRC, match_opcode, 0 },
{"csrrc",     "I",   "d,E,Z",  MATCH_CSRRCI, MASK_CSRRCI, match_opcode, INSN_ALIAS },
{"uret",      "I",   "",     MATCH_URET, MASK_URET, match_opcode, 0 },
{"sret",      "I",   "",     MATCH_SRET, MASK_SRET, match_opcode, 0 },
{"hret",      "I",   "",     MATCH_HRET, MASK_HRET, match_opcode, 0 },
{"mret",      "I",   "",     MATCH_MRET, MASK_MRET, match_opcode, 0 },
{"dret",      "I",   "",     MATCH_DRET, MASK_DRET, match_opcode, 0 },
{"sfence.vm", "I",   "",     MATCH_SFENCE_VM, MASK_SFENCE_VM | MASK_RS1, match_opcode, 0 },
{"sfence.vm", "I",   "s",    MATCH_SFENCE_VM, MASK_SFENCE_VM, match_opcode, 0 },
{"sfence.vma","I",   "",     MATCH_SFENCE_VMA, MASK_SFENCE_VMA | MASK_RS1 | MASK_RS2, match_opcode, INSN_ALIAS },
{"sfence.vma","I",   "s",    MATCH_SFENCE_VMA, MASK_SFENCE_VMA | MASK_RS2, match_opcode, INSN_ALIAS },
{"sfence.vma","I",   "s,t",  MATCH_SFENCE_VMA, MASK_SFENCE_VMA, match_opcode, 0 },
{"wfi",       "I",   "",     MATCH_WFI, MASK_WFI, match_opcode, 0 },

/* Rocket Custom Coprocessor extension */
{"custom2",   "Xcustom", "d,s,t,^j", MATCH_CUSTOM2_RD_RS1_RS2, MASK_CUSTOM2_RD_RS1_RS2, match_opcode, 0},
{"custom2",   "Xcustom", "d,s,^t,^j", MATCH_CUSTOM2_RD_RS1, MASK_CUSTOM2_RD_RS1, match_opcode, 0},
{"custom2",   "Xcustom", "d,^s,^t,^j", MATCH_CUSTOM2_RD, MASK_CUSTOM2_RD, match_opcode, 0},
{"custom2",   "Xcustom", "^d,s,t,^j", MATCH_CUSTOM2_RS1_RS2, MASK_CUSTOM2_RS1_RS2, match_opcode, 0},
{"custom2",   "Xcustom", "^d,s,^t,^j", MATCH_CUSTOM2_RS1, MASK_CUSTOM2_RS1, match_opcode, 0},
{"custom2",   "Xcustom", "^d,^s,^t,^j", MATCH_CUSTOM2, MASK_CUSTOM2, match_opcode, 0},
{"custom3",   "Xcustom", "d,s,t,^j", MATCH_CUSTOM3_RD_RS1_RS2, MASK_CUSTOM3_RD_RS1_RS2, match_opcode, 0},
{"custom3",   "Xcustom", "d,s,^t,^j", MATCH_CUSTOM3_RD_RS1, MASK_CUSTOM3_RD_RS1, match_opcode, 0},
{"custom3",   "Xcustom", "d,^s,^t,^j", MATCH_CUSTOM3_RD, MASK_CUSTOM3_RD, match_opcode, 0},
{"custom3",   "Xcustom", "^d,s,t,^j", MATCH_CUSTOM3_RS1_RS2, MASK_CUSTOM3_RS1_RS2, match_opcode, 0},
{"custom3",   "Xcustom", "^d,s,^t,^j", MATCH_CUSTOM3_RS1, MASK_CUSTOM3_RS1, match_opcode, 0},
{"custom3",   "Xcustom", "^d,^s,^t,^j", MATCH_CUSTOM3, MASK_CUSTOM3, match_opcode, 0},

/* Xhwacha extension ct instructions*/
{"vsetcfg",   "Xhwacha", "s", MATCH_VSETCFG, MASK_VSETCFG | MASK_IMM, match_opcode, 0},
{"vsetcfg",   "Xhwacha", "#g,#f", MATCH_VSETCFG, MASK_VSETCFG | MASK_RS1, match_opcode, 0},
{"vsetcfg",   "Xhwacha", "s,#g,#f", MATCH_VSETCFG, MASK_VSETCFG, match_opcode, 0},
{"vsetcfg",   "Xhwacha", "d,#C", 0, (int) M_VSETCFG, match_never, INSN_MACRO},
{"vsetucfg",  "Xhwacha", "d,u", MATCH_LUI, MASK_LUI, match_opcode, INSN_ALIAS},
{"vsetvl",    "Xhwacha", "d,s", MATCH_VSETVL, MASK_VSETVL, match_opcode, 0},
{"vgetcfg",   "Xhwacha", "d", MATCH_VGETCFG, MASK_VGETCFG, match_opcode, 0},
{"vgetvl",    "Xhwacha", "d", MATCH_VGETVL, MASK_VGETVL, match_opcode, 0},
{"vuncfg",    "Xhwacha", "", MATCH_VUNCFG, MASK_VUNCFG, match_opcode, 0},

{"vmcs",      "Xhwacha", "#E,s", MATCH_VMCS, MASK_VMCS, match_opcode, 0},
{"vmca",      "Xhwacha", "#e,s", MATCH_VMCA, MASK_VMCA, match_opcode, 0},

{"vf",        "Xhwacha", "q(s)", MATCH_VF, MASK_VF, match_opcode, 0},
{"vf",        "Xhwacha", "A,s", 0, (int) M_VF, match_never, INSN_MACRO },

{"vxcptcause",   "Xhwacha", "d", MATCH_VXCPTCAUSE, MASK_VXCPTCAUSE, match_opcode, 0},
{"vxcptval",     "Xhwacha", "d", MATCH_VXCPTVAL, MASK_VXCPTVAL, match_opcode, 0},
{"vxcptpc",      "Xhwacha", "d", MATCH_VXCPTPC, MASK_VXCPTPC, match_opcode, 0},

{"vxcptret",     "Xhwacha", "", MATCH_VXCPTRET, MASK_VXCPTRET, match_opcode, 0},
{"vxcptkill",    "Xhwacha", "", MATCH_VXCPTKILL, MASK_VXCPTKILL, match_opcode, 0},

{"vfence.vma", "Xhwacha", "", MATCH_VFENCE_VMA, MASK_VFENCE_VMA | MASK_RS1 | MASK_RS2, match_opcode, INSN_ALIAS },
{"vfence.vma", "Xhwacha", "s", MATCH_VFENCE_VMA, MASK_VFENCE_VMA | MASK_RS2, match_opcode, INSN_ALIAS },
{"vfence.vma", "Xhwacha", "s,t", MATCH_VFENCE_VMA, MASK_VFENCE_VMA, match_opcode, 0},

/* Xhwacha extension work thread instructions*/
{"vstop",     "Xhwacha", "", MATCH_VSTOP, MASK_VSTOP, match_opcode, 0},
{"vfence",    "Xhwacha", "#G,#H", MATCH_VFENCE, MASK_VFENCE, match_opcode, 0},
{"vfence",    "Xhwacha", "",  MATCH_VFENCE | MASK_VPREV | MASK_VSUCC, MASK_VFENCE | MASK_VRD,  match_opcode,   INSN_ALIAS },
{"veidx",     "Xhwacha", "#N,#p,#d", MATCH_VEIDX, MASK_VEIDX | MASK_VRS1 | MASK_VS1, match_opcode, INSN_ALIAS},
{"veidx",     "Xhwacha", "#N,#p,#w,#d,#s", MATCH_VEIDX, MASK_VEIDX, match_opcode, 0},
{"vfirst",    "Xhwacha", "#N,#p,#D,#s", MATCH_VFIRST, MASK_VFIRST, match_opcode, 0},

/* work thread control flow instructions */
{"vcjal",     "Xhwacha", "#N,#p,#c,#D,#k", MATCH_VCJAL, MASK_VCJAL, match_opcode, 0},
{"vcjalr",    "Xhwacha", "#N,#p,#c,#D,#S,#k", MATCH_VCJALR, MASK_VCJALR, match_opcode, 0},

/* scalar load upper */
{"vlui",      "Xhwacha", "#D,#j", MATCH_VLUI, MASK_VLUI, match_opcode, 0},
{"vauipc",    "Xhwacha", "#D,#j", MATCH_VAUIPC, MASK_VAUIPC, match_opcode, 0},

/* vnop */
{"vnop",      "Xhwacha",   "",  MATCH_VADDI, MASK_VADDI | MASK_VRD | MASK_VRS1 | MASK_VIMM | MASK_VPRED | MASK_VN, match_opcode,  INSN_ALIAS},

/* vector loads */
/* unit stride */
/* xloads */
{"vld",       "Xhwacha", "#N,#p,#d,#A", MATCH_VLD, MASK_VLD, match_opcode, 0},
{"vlw",       "Xhwacha", "#N,#p,#d,#A", MATCH_VLW, MASK_VLW, match_opcode, 0},
{"vlwu",      "Xhwacha", "#N,#p,#d,#A", MATCH_VLWU, MASK_VLWU, match_opcode, 0},
{"vlh",       "Xhwacha", "#N,#p,#d,#A", MATCH_VLH, MASK_VLH, match_opcode, 0},
{"vlhu",      "Xhwacha", "#N,#p,#d,#A", MATCH_VLHU, MASK_VLHU, match_opcode, 0},
{"vlb",       "Xhwacha", "#N,#p,#d,#A", MATCH_VLB, MASK_VLB, match_opcode, 0},
{"vlbu",      "Xhwacha", "#N,#p,#d,#A", MATCH_VLBU, MASK_VLBU, match_opcode, 0},

/* stride */
/* xloads */
{"vlstd",     "Xhwacha", "#N,#p,#d,#A,#B", MATCH_VLSTD, MASK_VLSTD, match_opcode, 0},
{"vlstw",     "Xhwacha", "#N,#p,#d,#A,#B", MATCH_VLSTW, MASK_VLSTW, match_opcode, 0},
{"vlstwu",    "Xhwacha", "#N,#p,#d,#A,#B", MATCH_VLSTWU, MASK_VLSTWU, match_opcode, 0},
{"vlsth",     "Xhwacha", "#N,#p,#d,#A,#B", MATCH_VLSTH, MASK_VLSTH, match_opcode, 0},
{"vlsthu",    "Xhwacha", "#N,#p,#d,#A,#B", MATCH_VLSTHU, MASK_VLSTHU, match_opcode, 0},
{"vlstb",     "Xhwacha", "#N,#p,#d,#A,#B", MATCH_VLSTB, MASK_VLSTB, match_opcode, 0},
{"vlstbu",    "Xhwacha", "#N,#p,#d,#A,#B", MATCH_VLSTBU, MASK_VLSTBU, match_opcode, 0},

/* segment */
/* xloads */
{"vlsegd",    "Xhwacha", "#N,#p,#d,#A,#n", MATCH_VLSEGD, MASK_VLSEGD, match_opcode, 0},
{"vlsegw",    "Xhwacha", "#N,#p,#d,#A,#n", MATCH_VLSEGW, MASK_VLSEGW, match_opcode, 0},
{"vlsegwu",   "Xhwacha", "#N,#p,#d,#A,#n", MATCH_VLSEGWU, MASK_VLSEGWU, match_opcode, 0},
{"vlsegh",    "Xhwacha", "#N,#p,#d,#A,#n", MATCH_VLSEGH, MASK_VLSEGH, match_opcode, 0},
{"vlseghu",   "Xhwacha", "#N,#p,#d,#A,#n", MATCH_VLSEGHU, MASK_VLSEGHU, match_opcode, 0},
{"vlsegb",    "Xhwacha", "#N,#p,#d,#A,#n", MATCH_VLSEGB, MASK_VLSEGB, match_opcode, 0},
{"vlsegbu",   "Xhwacha", "#N,#p,#d,#A,#n", MATCH_VLSEGBU, MASK_VLSEGBU, match_opcode, 0},

/* stride segment */
/* xloads */
{"vlsegstd",  "Xhwacha", "#N,#p,#d,#A,#B,#n", MATCH_VLSEGSTD, MASK_VLSEGSTD, match_opcode, 0},
{"vlsegstw",  "Xhwacha", "#N,#p,#d,#A,#B,#n", MATCH_VLSEGSTW, MASK_VLSEGSTW, match_opcode, 0},
{"vlsegstwu", "Xhwacha", "#N,#p,#d,#A,#B,#n", MATCH_VLSEGSTWU, MASK_VLSEGSTWU, match_opcode, 0},
{"vlsegsth",  "Xhwacha", "#N,#p,#d,#A,#B,#n", MATCH_VLSEGSTH, MASK_VLSEGSTH, match_opcode, 0},
{"vlsegsthu", "Xhwacha", "#N,#p,#d,#A,#B,#n", MATCH_VLSEGSTHU, MASK_VLSEGSTHU, match_opcode, 0},
{"vlsegstb",  "Xhwacha", "#N,#p,#d,#A,#B,#n", MATCH_VLSEGSTB, MASK_VLSEGSTB, match_opcode, 0},
{"vlsegstbu", "Xhwacha", "#N,#p,#d,#A,#B,#n", MATCH_VLSEGSTBU, MASK_VLSEGSTBU, match_opcode, 0},

/* unit stride */
/* xstores */
{"vsd",       "Xhwacha", "#N,#p,#d,#A", MATCH_VSD, MASK_VSD, match_opcode, 0},
{"vsw",       "Xhwacha", "#N,#p,#d,#A", MATCH_VSW, MASK_VSW, match_opcode, 0},
{"vsh",       "Xhwacha", "#N,#p,#d,#A", MATCH_VSH, MASK_VSH, match_opcode, 0},
{"vsb",       "Xhwacha", "#N,#p,#d,#A", MATCH_VSB, MASK_VSB, match_opcode, 0},

/* stride */
/* xstores */
{"vsstd",     "Xhwacha", "#N,#p,#d,#A,#B", MATCH_VSSTD, MASK_VSSTD, match_opcode, 0},
{"vsstw",     "Xhwacha", "#N,#p,#d,#A,#B", MATCH_VSSTW, MASK_VSSTW, match_opcode, 0},
{"vssth",     "Xhwacha", "#N,#p,#d,#A,#B", MATCH_VSSTH, MASK_VSSTH, match_opcode, 0},
{"vsstb",     "Xhwacha", "#N,#p,#d,#A,#B", MATCH_VSSTB, MASK_VSSTB, match_opcode, 0},

/* segment */
/* xstores */
{"vssegd",    "Xhwacha", "#N,#p,#d,#A,#n", MATCH_VSSEGD, MASK_VSSEGD, match_opcode, 0},
{"vssegw",    "Xhwacha", "#N,#p,#d,#A,#n", MATCH_VSSEGW, MASK_VSSEGW, match_opcode, 0},
{"vssegh",    "Xhwacha", "#N,#p,#d,#A,#n", MATCH_VSSEGH, MASK_VSSEGH, match_opcode, 0},
{"vssegb",    "Xhwacha", "#N,#p,#d,#A,#n", MATCH_VSSEGB, MASK_VSSEGB, match_opcode, 0},

/* stride segment */
/* xsegstores */
{"vssegstd",  "Xhwacha", "#N,#p,#d,#A,#B,#n", MATCH_VSSEGSTD, MASK_VSSEGSTD, match_opcode, 0},
{"vssegstw",  "Xhwacha", "#N,#p,#d,#A,#B,#n", MATCH_VSSEGSTW, MASK_VSSEGSTW, match_opcode, 0},
{"vssegsth",  "Xhwacha", "#N,#p,#d,#A,#B,#n", MATCH_VSSEGSTH, MASK_VSSEGSTH, match_opcode, 0},
{"vssegstb",  "Xhwacha", "#N,#p,#d,#A,#B,#n", MATCH_VSSEGSTB, MASK_VSSEGSTB, match_opcode, 0},

/* indexed load/stores */
/* xloads */
{"vlxd",      "Xhwacha", "#N,#p,#d,#S,#t", MATCH_VLXD, MASK_VLXD, match_opcode, 0},
{"vlxw",      "Xhwacha", "#N,#p,#d,#S,#t", MATCH_VLXW, MASK_VLXW, match_opcode, 0},
{"vlxwu",     "Xhwacha", "#N,#p,#d,#S,#t", MATCH_VLXWU,MASK_VLXWU, match_opcode, 0},
{"vlxh",      "Xhwacha", "#N,#p,#d,#S,#t", MATCH_VLXH, MASK_VLXH, match_opcode, 0},
{"vlxhu",     "Xhwacha", "#N,#p,#d,#S,#t", MATCH_VLXHU,MASK_VLXHU, match_opcode, 0},
{"vlxb",      "Xhwacha", "#N,#p,#d,#S,#t", MATCH_VLXB, MASK_VLXB, match_opcode, 0},
{"vlxbu",     "Xhwacha", "#N,#p,#d,#S,#t", MATCH_VLXBU,MASK_VLXBU, match_opcode, 0},
/* xstores */
{"vsxd",      "Xhwacha", "#N,#p,#d,#S,#t", MATCH_VSXD, MASK_VSXD, match_opcode, 0},
{"vsxw",      "Xhwacha", "#N,#p,#d,#S,#t", MATCH_VSXW, MASK_VSXW, match_opcode, 0},
{"vsxh",      "Xhwacha", "#N,#p,#d,#S,#t", MATCH_VSXH, MASK_VSXH, match_opcode, 0},
{"vsxb",      "Xhwacha", "#N,#p,#d,#S,#t", MATCH_VSXB, MASK_VSXB, match_opcode, 0},

/* shared loads from shared registers */
/* xloads */
{"vlsd",      "Xhwacha", "#d,#S", MATCH_VLSD, MASK_VLSD, match_opcode, 0},
{"vlsw",      "Xhwacha", "#d,#S", MATCH_VLSW, MASK_VLSW, match_opcode, 0},
{"vlswu",     "Xhwacha", "#d,#S", MATCH_VLSWU,MASK_VLSWU, match_opcode, 0},
{"vlsh",      "Xhwacha", "#d,#S", MATCH_VLSH, MASK_VLSH, match_opcode, 0},
{"vlshu",     "Xhwacha", "#d,#S", MATCH_VLSHU,MASK_VLSHU, match_opcode, 0},
{"vlsb",      "Xhwacha", "#d,#S", MATCH_VLSB, MASK_VLSB, match_opcode, 0},
{"vlsbu",     "Xhwacha", "#d,#S", MATCH_VLSBU,MASK_VLSBU, match_opcode, 0},
/* xstores */
{"vssd",      "Xhwacha", "#S,#T", MATCH_VSSD, MASK_VSSD, match_opcode, 0},
{"vssw",      "Xhwacha", "#S,#T", MATCH_VSSW, MASK_VSSW, match_opcode, 0},
{"vssh",      "Xhwacha", "#S,#T", MATCH_VSSH, MASK_VSSH, match_opcode, 0},
{"vssb",      "Xhwacha", "#S,#T", MATCH_VSSB, MASK_VSSB, match_opcode, 0},

/* shared loads from address registers */
/* xloads */
{"vlad",      "Xhwacha", "#d,#A", MATCH_VLAD, MASK_VLAD, match_opcode, 0},
{"vlaw",      "Xhwacha", "#d,#A", MATCH_VLAW, MASK_VLAW, match_opcode, 0},
{"vlawu",     "Xhwacha", "#d,#A", MATCH_VLAWU,MASK_VLAWU, match_opcode, 0},
{"vlah",      "Xhwacha", "#d,#A", MATCH_VLAH, MASK_VLAH, match_opcode, 0},
{"vlahu",     "Xhwacha", "#d,#A", MATCH_VLAHU,MASK_VLAHU, match_opcode, 0},
{"vlab",      "Xhwacha", "#d,#A", MATCH_VLAB, MASK_VLAB, match_opcode, 0},
{"vlabu",     "Xhwacha", "#d,#A", MATCH_VLABU,MASK_VLABU, match_opcode, 0},
/* xstores */
{"vsad",      "Xhwacha", "#A,#T", MATCH_VSAD, MASK_VSAD, match_opcode, 0},
{"vsaw",      "Xhwacha", "#A,#T", MATCH_VSAW, MASK_VSAW, match_opcode, 0},
{"vsah",      "Xhwacha", "#A,#T", MATCH_VSAH, MASK_VSAH, match_opcode, 0},
{"vsab",      "Xhwacha", "#A,#T", MATCH_VSAB, MASK_VSAB, match_opcode, 0},

/* Vector-vector ut operations */
{"vandi",     "Xhwacha", "#d,#s,#j",  MATCH_VANDI, MASK_VANDI, match_opcode,   0 },
{"vand",      "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VAND, MASK_VAND, match_opcode,   0 },
{"vand",      "Xhwacha", "#d,#s,#j",  MATCH_VANDI, MASK_VANDI, match_opcode,   INSN_ALIAS },
{"vaddi",     "Xhwacha", "#d,#s,#j",  MATCH_VADDI, MASK_VADDI, match_opcode,  0 },
{"vadd",      "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VADD, MASK_VADD, match_opcode,  0 },
{"vadd",      "Xhwacha", "#N,#p,#v,#x,#d,#s,#t,0",MATCH_VADD, MASK_VADD, match_opcode,  0 },
{"vadd",      "Xhwacha", "#d,#s,#j",  MATCH_VADDI, MASK_VADDI, match_opcode,  INSN_ALIAS },
{"vslli",     "Xhwacha", "#d,#s,#>",   MATCH_VSLLI, MASK_VSLLI, match_opcode,   0 },
{"vsll",      "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",   MATCH_VSLL, MASK_VSLL, match_opcode,   0 },
{"vsll",      "Xhwacha", "#d,#s,#>",   MATCH_VSLLI, MASK_VSLLI, match_opcode,   INSN_ALIAS },
{"vsrli",     "Xhwacha", "#d,#s,#>",   MATCH_VSRLI, MASK_VSRLI, match_opcode,   0 },
{"vsrl",      "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",   MATCH_VSRL, MASK_VSRL, match_opcode,   0 },
{"vsrl",      "Xhwacha", "#d,#s,#>",   MATCH_VSRLI, MASK_VSRLI, match_opcode,   INSN_ALIAS },
{"vsrai",     "Xhwacha", "#d,#s,#>",   MATCH_VSRAI, MASK_VSRAI, match_opcode,   0 },
{"vsra",      "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",   MATCH_VSRA, MASK_VSRA, match_opcode,   0 },
{"vsra",      "Xhwacha", "#d,#s,#>",   MATCH_VSRAI, MASK_VSRAI, match_opcode,   INSN_ALIAS },
{"vsub",      "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VSUB, MASK_VSUB, match_opcode,   0 },
{"vori",      "Xhwacha", "#d,#s,#j",  MATCH_VORI, MASK_VORI, match_opcode,   0 },
{"vor",       "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VOR, MASK_VOR, match_opcode,   0 },
{"vor",       "Xhwacha", "#d,#s,#j",  MATCH_VORI, MASK_VORI, match_opcode,   INSN_ALIAS },
{"vseqz",     "Xhwacha", "#d,#s",  MATCH_VSLTIU | ENCODE_ITYPE_VIMM(1), MASK_VSLTIU | MASK_VIMM, match_opcode,   INSN_ALIAS },
{"vsnez",     "Xhwacha", "#N,#p,#v,#x,#d,#t",  MATCH_VSLTU, MASK_VSLTU | MASK_VRS1, match_opcode,   INSN_ALIAS },
{"vsltz",     "Xhwacha", "#N,#p,#v,#x,#d,#s",  MATCH_VSLT, MASK_VSLT | MASK_VRS2, match_opcode,   INSN_ALIAS },
{"vsgtz",     "Xhwacha", "#N,#p,#v,#x,#d,#t",  MATCH_VSLT, MASK_VSLT | MASK_VRS1, match_opcode,   INSN_ALIAS },
{"vslti",     "Xhwacha", "#d,#s,#j",  MATCH_VSLTI, MASK_VSLTI, match_opcode,   INSN_ALIAS },
{"vslt",      "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VSLT, MASK_VSLT, match_opcode,   0 },
{"vslt",      "Xhwacha", "#d,#s,#j",  MATCH_VSLTI, MASK_VSLTI, match_opcode,   0 },
{"vsltiu",    "Xhwacha", "#d,#s,#j",  MATCH_VSLTIU, MASK_VSLTIU, match_opcode,   0 },
{"vsltu",     "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VSLTU, MASK_VSLTU, match_opcode,   0 },
{"vsltu",     "Xhwacha", "#d,#s,#j",  MATCH_VSLTIU, MASK_VSLTIU, match_opcode,   INSN_ALIAS },
{"vsgt",      "Xhwacha", "#N,#p,#v,#x,#d,#t,#s",  MATCH_VSLT, MASK_VSLT, match_opcode,   INSN_ALIAS },
{"vsgtu",     "Xhwacha", "#N,#p,#v,#x,#d,#t,#s",  MATCH_VSLTU, MASK_VSLTU, match_opcode,   INSN_ALIAS },
{"vxori",     "Xhwacha", "#d,#s,#j",  MATCH_VXORI, MASK_VXORI, match_opcode,   0 },
{"vxor",      "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VXOR, MASK_VXOR, match_opcode,   0 },
{"vxor",      "Xhwacha", "#d,#s,#j",  MATCH_VXORI, MASK_VXORI, match_opcode,   INSN_ALIAS },
{"vsext.w",   "Xhwacha", "#d,#s",  MATCH_VADDIW, MASK_VADDIW | MASK_VIMM, match_opcode,   INSN_ALIAS },
{"vaddiw",    "Xhwacha", "#d,#s,#j",  MATCH_VADDIW, MASK_VADDIW, match_opcode,   0 },
{"vaddw",     "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VADDW, MASK_VADDW, match_opcode,   0 },
{"vaddw",     "Xhwacha", "#d,#s,#j",  MATCH_VADDIW, MASK_VADDIW, match_opcode,   INSN_ALIAS },
{"vnegw",     "Xhwacha", "#N,#p,#v,#x,#d,#t",  MATCH_VSUBW, MASK_VSUBW | MASK_VRS1, match_opcode,   INSN_ALIAS }, /* sub 0 */
{"vslliw",    "Xhwacha", "#d,#s,#<",   MATCH_VSLLIW, MASK_VSLLIW, match_opcode,   0 },
{"vsllw",     "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",   MATCH_VSLLW, MASK_VSLLW, match_opcode,   0 },
{"vsllw",     "Xhwacha", "#d,#s,#<",   MATCH_VSLLIW, MASK_VSLLIW, match_opcode,   INSN_ALIAS },
{"vsrliw",    "Xhwacha", "#d,#s,#<",   MATCH_VSRLIW, MASK_VSRLIW, match_opcode,   0 },
{"vsrlw",     "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",   MATCH_VSRLW, MASK_VSRLW, match_opcode,   0 },
{"vsrlw",     "Xhwacha", "#d,#s,#<",   MATCH_VSRLIW, MASK_VSRLIW, match_opcode,   INSN_ALIAS },
{"vsraiw",    "Xhwacha", "#d,#s,#<",   MATCH_VSRAIW, MASK_VSRAIW, match_opcode,   0 },
{"vsraw",     "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",   MATCH_VSRAW, MASK_VSRAW, match_opcode,   0 },
{"vsraw",     "Xhwacha", "#d,#s,#<",   MATCH_VSRAIW, MASK_VSRAIW, match_opcode,   INSN_ALIAS },
{"vsubw",     "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VSUBW, MASK_VSUBW, match_opcode,   0 },

/* Vector Comparison worker-thread operations */
{"vcmpeq",    "Xhwacha", "#N,#p,#x,#F,#s,#t",    MATCH_VCMPEQ, MASK_VCMPEQ, match_opcode,  0 },
{"vcmplt",    "Xhwacha", "#N,#p,#x,#F,#s,#t",    MATCH_VCMPLT, MASK_VCMPLT, match_opcode,  0 },
{"vcmpltu",   "Xhwacha", "#N,#p,#x,#F,#s,#t",    MATCH_VCMPLTU, MASK_VCMPLTU, match_opcode,  0 },

/* Vector predicate register load/stores */
{"vpl", "Xhwacha", "#N,#p,#F,#A", MATCH_VPL, MASK_VPL, match_opcode, 0},
{"vps", "Xhwacha", "#N,#p,#P,#A", MATCH_VPS, MASK_VPS, match_opcode, 0},

/* Vector predicate register arithmetic */
{"vpop",     "Xhwacha",   "#F,#O,#P,#Q,#z", MATCH_VPOP, MASK_VPOP, match_opcode, 0 },
{"vpclear",  "Xhwacha",   "#F",    MATCH_VPCLEAR, MASK_VPCLEAR, match_opcode, 0 },
{"vpset",    "Xhwacha",   "#F",    MATCH_VPSET, MASK_VPSET, match_opcode, 0 },
{"vpxorxor", "Xhwacha",   "#F,#O,#P,#Q",    MATCH_VPXORXOR, MASK_VPXORXOR, match_opcode, 0 },
{"vpxorand", "Xhwacha",   "#F,#O,#P,#Q",    MATCH_VPXORAND, MASK_VPXORAND, match_opcode, 0 },
{"vpxoror",  "Xhwacha",   "#F,#O,#P,#Q",    MATCH_VPXOROR, MASK_VPXOROR, match_opcode, 0 },
{"vpandxor", "Xhwacha",   "#F,#O,#P,#Q",    MATCH_VPANDXOR, MASK_VPANDXOR, match_opcode, 0 },
{"vpandand", "Xhwacha",   "#F,#O,#P,#Q",    MATCH_VPANDAND, MASK_VPANDAND, match_opcode, 0 },
{"vpandor",  "Xhwacha",   "#F,#O,#P,#Q",    MATCH_VPANDOR, MASK_VPANDOR, match_opcode, 0 },
{"vporxor",  "Xhwacha",   "#F,#O,#P,#Q",    MATCH_VPORXOR, MASK_VPORXOR, match_opcode, 0 },
{"vporand",  "Xhwacha",   "#F,#O,#P,#Q",    MATCH_VPORAND, MASK_VPORAND, match_opcode, 0 },
{"vporor",   "Xhwacha",   "#F,#O,#P,#Q",    MATCH_VPOROR, MASK_VPOROR, match_opcode, 0 },

/* Atomic memory operation instruction subset */
{"vamoadd.w",     "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOADD_W, MASK_VAMOADD_W | MASK_VAQRL, match_opcode,   0 },
{"vamoswap.w",    "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOSWAP_W, MASK_VAMOSWAP_W | MASK_VAQRL, match_opcode,   0 },
{"vamoand.w",     "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOAND_W, MASK_VAMOAND_W | MASK_VAQRL, match_opcode,   0 },
{"vamoor.w",      "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOOR_W, MASK_VAMOOR_W | MASK_VAQRL, match_opcode,   0 },
{"vamoxor.w",     "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOXOR_W, MASK_VAMOXOR_W | MASK_VAQRL, match_opcode,   0 },
{"vamomax.w",     "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMAX_W, MASK_VAMOMAX_W | MASK_VAQRL, match_opcode,   0 },
{"vamomaxu.w",    "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMAXU_W, MASK_VAMOMAXU_W | MASK_VAQRL, match_opcode,   0 },
{"vamomin.w",     "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMIN_W, MASK_VAMOMIN_W | MASK_VAQRL, match_opcode,   0 },
{"vamominu.w",    "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMINU_W, MASK_VAMOMINU_W | MASK_VAQRL, match_opcode,   0 },
{"vamoadd.w.aq",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOADD_W | MASK_VAQ, MASK_VAMOADD_W | MASK_VAQRL, match_opcode,   0 },
{"vamoswap.w.aq", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOSWAP_W | MASK_VAQ, MASK_VAMOSWAP_W | MASK_VAQRL, match_opcode,   0 },
{"vamoand.w.aq",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOAND_W | MASK_VAQ, MASK_VAMOAND_W | MASK_VAQRL, match_opcode,   0 },
{"vamoor.w.aq",   "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOOR_W | MASK_VAQ, MASK_VAMOOR_W | MASK_VAQRL, match_opcode,   0 },
{"vamoxor.w.aq",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOXOR_W | MASK_VAQ, MASK_VAMOXOR_W | MASK_VAQRL, match_opcode,   0 },
{"vamomax.w.aq",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMAX_W | MASK_VAQ, MASK_VAMOMAX_W | MASK_VAQRL, match_opcode,   0 },
{"vamomaxu.w.aq", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMAXU_W | MASK_VAQ, MASK_VAMOMAXU_W | MASK_VAQRL, match_opcode,   0 },
{"vamomin.w.aq",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMIN_W | MASK_VAQ, MASK_VAMOMIN_W | MASK_VAQRL, match_opcode,   0 },
{"vamominu.w.aq", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMINU_W | MASK_VAQ, MASK_VAMOMINU_W | MASK_VAQRL, match_opcode,   0 },
{"vamoadd.w.rl",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOADD_W | MASK_VRL, MASK_VAMOADD_W | MASK_VAQRL, match_opcode,   0 },
{"vamoswap.w.rl", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOSWAP_W | MASK_VRL, MASK_VAMOSWAP_W | MASK_VAQRL, match_opcode,   0 },
{"vamoand.w.rl",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOAND_W | MASK_VRL, MASK_VAMOAND_W | MASK_VAQRL, match_opcode,   0 },
{"vamoor.w.rl",   "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOOR_W | MASK_VRL, MASK_VAMOOR_W | MASK_VAQRL, match_opcode,   0 },
{"vamoxor.w.rl",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOXOR_W | MASK_VRL, MASK_VAMOXOR_W | MASK_VAQRL, match_opcode,   0 },
{"vamomax.w.rl",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMAX_W | MASK_VRL, MASK_VAMOMAX_W | MASK_VAQRL, match_opcode,   0 },
{"vamomaxu.w.rl", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMAXU_W | MASK_VRL, MASK_VAMOMAXU_W | MASK_VAQRL, match_opcode,   0 },
{"vamomin.w.rl",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMIN_W | MASK_VRL, MASK_VAMOMIN_W | MASK_VAQRL, match_opcode,   0 },
{"vamominu.w.rl", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMINU_W | MASK_VRL, MASK_VAMOMINU_W | MASK_VAQRL, match_opcode,   0 },
{"vamoadd.w.sc",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOADD_W | MASK_VAQRL, MASK_VAMOADD_W | MASK_VAQRL, match_opcode,   0 },
{"vamoswap.w.sc", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOSWAP_W | MASK_VAQRL, MASK_VAMOSWAP_W | MASK_VAQRL, match_opcode,   0 },
{"vamoand.w.sc",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOAND_W | MASK_VAQRL, MASK_VAMOAND_W | MASK_VAQRL, match_opcode,   0 },
{"vamoor.w.sc",   "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOOR_W | MASK_VAQRL, MASK_VAMOOR_W | MASK_VAQRL, match_opcode,   0 },
{"vamoxor.w.sc",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOXOR_W | MASK_VAQRL, MASK_VAMOXOR_W | MASK_VAQRL, match_opcode,   0 },
{"vamomax.w.sc",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMAX_W | MASK_VAQRL, MASK_VAMOMAX_W | MASK_VAQRL, match_opcode,   0 },
{"vamomaxu.w.sc", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMAXU_W | MASK_VAQRL, MASK_VAMOMAXU_W | MASK_VAQRL, match_opcode,   0 },
{"vamomin.w.sc",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMIN_W | MASK_VAQRL, MASK_VAMOMIN_W | MASK_VAQRL, match_opcode,   0 },
{"vamominu.w.sc", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMINU_W | MASK_VAQRL, MASK_VAMOMINU_W | MASK_VAQRL, match_opcode,   0 },
{"vamoadd.d",     "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOADD_D, MASK_VAMOADD_D | MASK_VAQRL, match_opcode,   0 },
{"vamoswap.d",    "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOSWAP_D, MASK_VAMOSWAP_D | MASK_VAQRL, match_opcode,   0 },
{"vamoand.d",     "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOAND_D, MASK_VAMOAND_D | MASK_VAQRL, match_opcode,   0 },
{"vamoor.d",      "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOOR_D, MASK_VAMOOR_D | MASK_VAQRL, match_opcode,   0 },
{"vamoxor.d",     "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOXOR_D, MASK_VAMOXOR_D | MASK_VAQRL, match_opcode,   0 },
{"vamomax.d",     "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMAX_D, MASK_VAMOMAX_D | MASK_VAQRL, match_opcode,   0 },
{"vamomaxu.d",    "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMAXU_D, MASK_VAMOMAXU_D | MASK_VAQRL, match_opcode,   0 },
{"vamomin.d",     "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMIN_D, MASK_VAMOMIN_D | MASK_VAQRL, match_opcode,   0 },
{"vamominu.d",    "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMINU_D, MASK_VAMOMINU_D | MASK_VAQRL, match_opcode,   0 },
{"vamoadd.d.aq",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOADD_D | MASK_VAQ, MASK_VAMOADD_D | MASK_VAQRL, match_opcode,   0 },
{"vamoswap.d.aq", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOSWAP_D | MASK_VAQ, MASK_VAMOSWAP_D | MASK_VAQRL, match_opcode,   0 },
{"vamoand.d.aq",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOAND_D | MASK_VAQ, MASK_VAMOAND_D | MASK_VAQRL, match_opcode,   0 },
{"vamoor.d.aq",   "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOOR_D | MASK_VAQ, MASK_VAMOOR_D | MASK_VAQRL, match_opcode,   0 },
{"vamoxor.d.aq",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOXOR_D | MASK_VAQ, MASK_VAMOXOR_D | MASK_VAQRL, match_opcode,   0 },
{"vamomax.d.aq",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMAX_D | MASK_VAQ, MASK_VAMOMAX_D | MASK_VAQRL, match_opcode,   0 },
{"vamomaxu.d.aq", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMAXU_D | MASK_VAQ, MASK_VAMOMAXU_D | MASK_VAQRL, match_opcode,   0 },
{"vamomin.d.aq",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMIN_D | MASK_VAQ, MASK_VAMOMIN_D | MASK_VAQRL, match_opcode,   0 },
{"vamominu.d.aq", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMINU_D | MASK_VAQ, MASK_VAMOMINU_D | MASK_VAQRL, match_opcode,   0 },
{"vamoadd.d.rl",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOADD_D | MASK_VRL, MASK_VAMOADD_D | MASK_VAQRL, match_opcode,   0 },
{"vamoswap.d.rl", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOSWAP_D | MASK_VRL, MASK_VAMOSWAP_D | MASK_VAQRL, match_opcode,   0 },
{"vamoand.d.rl",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOAND_D | MASK_VRL, MASK_VAMOAND_D | MASK_VAQRL, match_opcode,   0 },
{"vamoor.d.rl",   "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOOR_D | MASK_VRL, MASK_VAMOOR_D | MASK_VAQRL, match_opcode,   0 },
{"vamoxor.d.rl",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOXOR_D | MASK_VRL, MASK_VAMOXOR_D | MASK_VAQRL, match_opcode,   0 },
{"vamomax.d.rl",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMAX_D | MASK_VRL, MASK_VAMOMAX_D | MASK_VAQRL, match_opcode,   0 },
{"vamomaxu.d.rl", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMAXU_D | MASK_VRL, MASK_VAMOMAXU_D | MASK_VAQRL, match_opcode,   0 },
{"vamomin.d.rl",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMIN_D | MASK_VRL, MASK_VAMOMIN_D | MASK_VAQRL, match_opcode,   0 },
{"vamominu.d.rl", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMINU_D | MASK_VRL, MASK_VAMOMINU_D | MASK_VAQRL, match_opcode,   0 },
{"vamoadd.d.sc",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOADD_D | MASK_VAQRL, MASK_VAMOADD_D | MASK_VAQRL, match_opcode,   0 },
{"vamoswap.d.sc", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOSWAP_D | MASK_VAQRL, MASK_VAMOSWAP_D | MASK_VAQRL, match_opcode,   0 },
{"vamoand.d.sc",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOAND_D | MASK_VAQRL, MASK_VAMOAND_D | MASK_VAQRL, match_opcode,   0 },
{"vamoor.d.sc",   "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOOR_D | MASK_VAQRL, MASK_VAMOOR_D | MASK_VAQRL, match_opcode,   0 },
{"vamoxor.d.sc",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOXOR_D | MASK_VAQRL, MASK_VAMOXOR_D | MASK_VAQRL, match_opcode,   0 },
{"vamomax.d.sc",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMAX_D | MASK_VAQRL, MASK_VAMOMAX_D | MASK_VAQRL, match_opcode,   0 },
{"vamomaxu.d.sc", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMAXU_D | MASK_VAQRL, MASK_VAMOMAXU_D | MASK_VAQRL, match_opcode,   0 },
{"vamomin.d.sc",  "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMIN_D | MASK_VAQRL, MASK_VAMOMIN_D | MASK_VAQRL, match_opcode,   0 },
{"vamominu.d.sc", "Xhwacha", "#N,#p,#v,#x,#d,0(#s),#t",  MATCH_VAMOMINU_D | MASK_VAQRL, MASK_VAMOMINU_D | MASK_VAQRL, match_opcode,   0 },

/* Multiply/Divide instruction subset */
{"vmul",       "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VMUL, MASK_VMUL, match_opcode,  0 },
{"vmulh",      "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VMULH, MASK_VMULH, match_opcode,  0 },
{"vmulhu",     "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VMULHU, MASK_VMULHU, match_opcode,  0 },
{"vmulhsu",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VMULHSU, MASK_VMULHSU, match_opcode,  0 },
{"vdiv",       "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VDIV, MASK_VDIV, match_opcode,  0 },
{"vdivu",      "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VDIVU, MASK_VDIVU, match_opcode,  0 },
{"vrem",       "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VREM, MASK_VREM, match_opcode,  0 },
{"vremu",      "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VREMU, MASK_VREMU, match_opcode,  0 },
{"vmulw",      "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VMULW, MASK_VMULW, match_opcode,  0 },
{"vdivw",      "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VDIVW, MASK_VDIVW, match_opcode,  0 },
{"vdivuw",     "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VDIVUW, MASK_VDIVUW, match_opcode,  0 },
{"vremw",      "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VREMW, MASK_VREMW, match_opcode,  0 },
{"vremuw",     "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VREMUW, MASK_VREMUW, match_opcode,  0 },

/* Single-precision floating-point instruction subset */
{"vfmv.s",     "Xhwacha", "#N,#p,#v,#x,#d,#u",  MATCH_VFSGNJ_S, MASK_VFSGNJ_S, match_rs1_eq_rs2,   INSN_ALIAS },
{"vfneg.s",    "Xhwacha", "#N,#p,#v,#x,#d,#u",  MATCH_VFSGNJN_S, MASK_VFSGNJN_S, match_rs1_eq_rs2,   INSN_ALIAS },
{"vfabs.s",    "Xhwacha", "#N,#p,#v,#x,#d,#u",  MATCH_VFSGNJX_S, MASK_VFSGNJX_S, match_rs1_eq_rs2,   INSN_ALIAS },
{"vfsgnj.s",   "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFSGNJ_S, MASK_VFSGNJ_S, match_opcode,   0 },
{"vfsgnjn.s",  "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFSGNJN_S, MASK_VFSGNJN_S, match_opcode,   0 },
{"vfsgnjx.s",  "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFSGNJX_S, MASK_VFSGNJX_S, match_opcode,   0 },
{"vfadd.s",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFADD_S | MASK_VRM, MASK_VFADD_S | MASK_VRM, match_opcode,   0 },
{"vfadd.s",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFADD_S, MASK_VFADD_S, match_opcode,   0 },
{"vfsub.s",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFSUB_S | MASK_VRM, MASK_VFSUB_S | MASK_VRM, match_opcode,   0 },
{"vfsub.s",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFSUB_S, MASK_VFSUB_S, match_opcode,   0 },
{"vfmul.s",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFMUL_S | MASK_VRM, MASK_VFMUL_S | MASK_VRM, match_opcode,   0 },
{"vfmul.s",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFMUL_S, MASK_VFMUL_S, match_opcode,   0 },
{"vfdiv.s",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFDIV_S | MASK_VRM, MASK_VFDIV_S | MASK_VRM, match_opcode,   0 },
{"vfdiv.s",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFDIV_S, MASK_VFDIV_S, match_opcode,   0 },
{"vfsqrt.s",   "Xhwacha", "#N,#p,#v,#w,#d,#s",  MATCH_VFSQRT_S | MASK_VRM, MASK_VFSQRT_S | MASK_VRM, match_opcode,  0 },
{"vfsqrt.s",   "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFSQRT_S, MASK_VFSQRT_S, match_opcode,  0 },
{"vfmin.s",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFMIN_S, MASK_VFMIN_S, match_opcode,   0 },
{"vfmax.s",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFMAX_S, MASK_VFMAX_S, match_opcode,   0 },
{"vfmadd.s",   "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VFMADD_S | MASK_VRM, MASK_VFMADD_S | MASK_VRM, match_opcode,   0 },
{"vfmadd.s",   "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r,#m",  MATCH_VFMADD_S, MASK_VFMADD_S, match_opcode,   0 },
{"vfnmadd.s",  "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VFNMADD_S | MASK_VRM, MASK_VFNMADD_S | MASK_VRM, match_opcode,   0 },
{"vfnmadd.s",  "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r,#m",  MATCH_VFNMADD_S, MASK_VFNMADD_S, match_opcode,   0 },
{"vfmsub.s",   "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VFMSUB_S | MASK_VRM, MASK_VFMSUB_S | MASK_VRM, match_opcode,   0 },
{"vfmsub.s",   "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r,#m",  MATCH_VFMSUB_S, MASK_VFMSUB_S, match_opcode,   0 },
{"vfnmsub.s",  "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VFNMSUB_S | MASK_VRM, MASK_VFNMSUB_S | MASK_VRM, match_opcode,   0 },
{"vfnmsub.s",  "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r,#m",  MATCH_VFNMSUB_S, MASK_VFNMSUB_S, match_opcode,   0 },
{"vfclass.s",  "Xhwacha", "#N,#p,#v,#w,#d,#s",  MATCH_VFCLASS_S, MASK_VFCLASS_S, match_opcode,   0 },
{"vcmpfeq.s",  "Xhwacha", "#N,#p,#x,#F,#s,#t",    MATCH_VCMPFEQ_S, MASK_VCMPFEQ_S, match_opcode,  0 },
{"vcmpflt.s",  "Xhwacha", "#N,#p,#x,#F,#s,#t",    MATCH_VCMPFLT_S, MASK_VCMPFLT_S, match_opcode,  0 },
{"vcmpfle.s",  "Xhwacha", "#N,#p,#x,#F,#s,#t",    MATCH_VCMPFLE_S, MASK_VCMPFLE_S, match_opcode,  0 },
{"vcmpfgt.s",  "Xhwacha", "#N,#p,#x,#F,#t,#s",    MATCH_VCMPFLT_S, MASK_VCMPFLT_S, match_opcode,  0 },
{"vcmpfge.s",  "Xhwacha", "#N,#p,#x,#F,#t,#s",    MATCH_VCMPFLE_S, MASK_VCMPFLE_S, match_opcode,  0 },
{"vfcvt.w.s",  "Xhwacha", "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_W_S | MASK_VRM, MASK_VFCVT_W_S | MASK_VRM, match_opcode,  0 },
{"vfcvt.w.s",  "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_W_S, MASK_VFCVT_W_S, match_opcode,  0 },
{"vfcvt.wu.s", "Xhwacha", "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_WU_S | MASK_VRM, MASK_VFCVT_WU_S | MASK_VRM, match_opcode,  0 },
{"vfcvt.wu.s", "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_WU_S, MASK_VFCVT_WU_S, match_opcode,  0 },
{"vfcvt.s.w",  "Xhwacha", "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_S_W | MASK_VRM, MASK_VFCVT_S_W | MASK_VRM, match_opcode,   0 },
{"vfcvt.s.w",  "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_S_W, MASK_VFCVT_S_W, match_opcode,   0 },
{"vfcvt.s.wu", "Xhwacha", "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_S_WU | MASK_VRM, MASK_VFCVT_S_W | MASK_VRM, match_opcode,   0 },
{"vfcvt.s.wu", "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_S_WU, MASK_VFCVT_S_WU, match_opcode,   0 },
{"vfcvt.l.s",  "Xhwacha", "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_L_S | MASK_VRM, MASK_VFCVT_L_S | MASK_VRM, match_opcode,  0 },
{"vfcvt.l.s",  "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_L_S, MASK_VFCVT_L_S, match_opcode,  0 },
{"vfcvt.lu.s", "Xhwacha", "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_LU_S | MASK_VRM, MASK_VFCVT_LU_S | MASK_VRM, match_opcode,  0 },
{"vfcvt.lu.s", "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_LU_S, MASK_VFCVT_LU_S, match_opcode,  0 },
{"vfcvt.s.l",  "Xhwacha", "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_S_L | MASK_VRM, MASK_VFCVT_S_L | MASK_VRM, match_opcode,   0 },
{"vfcvt.s.l",  "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_S_L, MASK_VFCVT_S_L, match_opcode,   0 },
{"vfcvt.s.lu", "Xhwacha", "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_S_LU | MASK_VRM, MASK_VFCVT_S_L | MASK_VRM, match_opcode,   0 },
{"vfcvt.s.lu", "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_S_LU, MASK_VFCVT_S_LU, match_opcode,   0 },

/* Double-precision floating-point instruction subset */
{"vfmv.d",     "Xhwacha", "#N,#p,#v,#x,#d,#u",  MATCH_VFSGNJ_D, MASK_VFSGNJ_D, match_rs1_eq_rs2,   INSN_ALIAS },
{"vfneg.d",    "Xhwacha", "#N,#p,#v,#x,#d,#u",  MATCH_VFSGNJN_D, MASK_VFSGNJN_D, match_rs1_eq_rs2,   INSN_ALIAS },
{"vfabs.d",    "Xhwacha", "#N,#p,#v,#x,#d,#u",  MATCH_VFSGNJX_D, MASK_VFSGNJX_D, match_rs1_eq_rs2,   INSN_ALIAS },
{"vfsgnj.d",   "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFSGNJ_D, MASK_VFSGNJ_D, match_opcode,   0 },
{"vfsgnjn.d",  "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFSGNJN_D, MASK_VFSGNJN_D, match_opcode,   0 },
{"vfsgnjx.d",  "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFSGNJX_D, MASK_VFSGNJX_D, match_opcode,   0 },
{"vfadd.d",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFADD_D | MASK_VRM, MASK_VFADD_D | MASK_VRM, match_opcode,   0 },
{"vfadd.d",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFADD_D, MASK_VFADD_D, match_opcode,   0 },
{"vfsub.d",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFSUB_D | MASK_VRM, MASK_VFSUB_D | MASK_VRM, match_opcode,   0 },
{"vfsub.d",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFSUB_D, MASK_VFSUB_D, match_opcode,   0 },
{"vfmul.d",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFMUL_D | MASK_VRM, MASK_VFMUL_D | MASK_VRM, match_opcode,   0 },
{"vfmul.d",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFMUL_D, MASK_VFMUL_D, match_opcode,   0 },
{"vfdiv.d",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFDIV_D | MASK_VRM, MASK_VFDIV_D | MASK_VRM, match_opcode,   0 },
{"vfdiv.d",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFDIV_D, MASK_VFDIV_D, match_opcode,   0 },
{"vfsqrt.d",   "Xhwacha", "#N,#p,#v,#w,#d,#s",  MATCH_VFSQRT_D | MASK_VRM, MASK_VFSQRT_D | MASK_VRM, match_opcode,  0 },
{"vfsqrt.d",   "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFSQRT_D, MASK_VFSQRT_D, match_opcode,  0 },
{"vfmin.d",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFMIN_D, MASK_VFMIN_D, match_opcode,   0 },
{"vfmax.d",    "Xhwacha", "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFMAX_D, MASK_VFMAX_D, match_opcode,   0 },
{"vfmadd.d",   "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VFMADD_D | MASK_VRM, MASK_VFMADD_D | MASK_VRM, match_opcode,   0 },
{"vfmadd.d",   "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r,#m",  MATCH_VFMADD_D, MASK_VFMADD_D, match_opcode,   0 },
{"vfnmadd.d",  "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VFNMADD_D | MASK_VRM, MASK_VFNMADD_D | MASK_VRM, match_opcode,   0 },
{"vfnmadd.d",  "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r,#m",  MATCH_VFNMADD_D, MASK_VFNMADD_D, match_opcode,   0 },
{"vfmsub.d",   "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VFMSUB_D | MASK_VRM, MASK_VFMSUB_D | MASK_VRM, match_opcode,   0 },
{"vfmsub.d",   "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r,#m",  MATCH_VFMSUB_D, MASK_VFMSUB_D, match_opcode,   0 },
{"vfnmsub.d",  "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VFNMSUB_D | MASK_VRM, MASK_VFNMSUB_D | MASK_VRM, match_opcode,   0 },
{"vfnmsub.d",  "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r,#m",  MATCH_VFNMSUB_D, MASK_VFNMSUB_D, match_opcode,   0 },
{"vfcvt.d.s",  "Xhwacha", "#N,#p,#v,#w,#d,#s",  MATCH_VFCVT_D_S, MASK_VFCVT_D_S | MASK_VRM, match_opcode,   0 },
{"vfcvt.s.d",  "Xhwacha", "#N,#p,#v,#w,#d,#s",  MATCH_VFCVT_S_D | MASK_VRM, MASK_VFCVT_S_D | MASK_VRM, match_opcode,   0 },
{"vfcvt.s.d",  "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_S_D, MASK_VFCVT_S_D, match_opcode,   0 },
{"vfclass.d",  "Xhwacha", "#N,#p,#v,#w,#d,#s",  MATCH_VFCLASS_D, MASK_VFCLASS_D, match_opcode,   0 },
{"vcmpfeq.d",  "Xhwacha", "#N,#p,#x,#F,#s,#t",    MATCH_VCMPFEQ_D, MASK_VCMPFEQ_D, match_opcode,  0 },
{"vcmpflt.d",  "Xhwacha", "#N,#p,#x,#F,#s,#t",    MATCH_VCMPFLT_D, MASK_VCMPFLT_D, match_opcode,  0 },
{"vcmpfle.d",  "Xhwacha", "#N,#p,#x,#F,#s,#t",    MATCH_VCMPFLE_D, MASK_VCMPFLE_D, match_opcode,  0 },
{"vcmpfgt.d",  "Xhwacha", "#N,#p,#x,#F,#t,#s",    MATCH_VCMPFLT_D, MASK_VCMPFLT_D, match_opcode,  0 },
{"vcmpfge.d",  "Xhwacha", "#N,#p,#x,#F,#t,#s",    MATCH_VCMPFLE_D, MASK_VCMPFLE_D, match_opcode,  0 },
{"vfcvt.w.d",  "Xhwacha", "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_W_D | MASK_VRM, MASK_VFCVT_W_D | MASK_VRM, match_opcode,  0 },
{"vfcvt.w.d",  "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_W_D, MASK_VFCVT_W_D, match_opcode,  0 },
{"vfcvt.wu.d", "Xhwacha", "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_WU_D | MASK_VRM, MASK_VFCVT_WU_D | MASK_VRM, match_opcode,  0 },
{"vfcvt.wu.d", "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_WU_D, MASK_VFCVT_WU_D, match_opcode,  0 },
{"vfcvt.d.w",  "Xhwacha", "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_D_W | MASK_VRM, MASK_VFCVT_D_W | MASK_VRM, match_opcode,   0 },
{"vfcvt.d.w",  "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_D_W, MASK_VFCVT_D_W, match_opcode,   0 },
{"vfcvt.d.wu", "Xhwacha", "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_D_WU | MASK_VRM, MASK_VFCVT_D_W | MASK_VRM, match_opcode,   0 },
{"vfcvt.d.wu", "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_D_WU, MASK_VFCVT_D_WU, match_opcode,   0 },
{"vfcvt.l.d",  "Xhwacha", "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_L_D | MASK_VRM, MASK_VFCVT_L_D | MASK_VRM, match_opcode,  0 },
{"vfcvt.l.d",  "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_L_D, MASK_VFCVT_L_D, match_opcode,  0 },
{"vfcvt.lu.d", "Xhwacha", "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_LU_D | MASK_VRM, MASK_VFCVT_LU_D | MASK_VRM, match_opcode,  0 },
{"vfcvt.lu.d", "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_LU_D, MASK_VFCVT_LU_D, match_opcode,  0 },
{"vfcvt.d.l",  "Xhwacha", "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_D_L | MASK_VRM, MASK_VFCVT_D_L | MASK_VRM, match_opcode,   0 },
{"vfcvt.d.l",  "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_D_L, MASK_VFCVT_D_L, match_opcode,   0 },
{"vfcvt.d.lu", "Xhwacha", "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_D_LU | MASK_VRM, MASK_VFCVT_D_L | MASK_VRM, match_opcode,   0 },
{"vfcvt.d.lu", "Xhwacha", "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_D_LU, MASK_VFCVT_D_LU, match_opcode,   0 },

/* Half-precision floating-point instruction subset */
{"vfsgnj.h",   "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFSGNJ_H, MASK_VFSGNJ_H, match_opcode,  0 },
{"vfsgnjn.h",  "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFSGNJN_H, MASK_VFSGNJN_H, match_opcode,  0 },
{"vfsgnjx.h",  "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFSGNJX_H, MASK_VFSGNJX_H, match_opcode,  0 },
{"vfadd.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFADD_H | MASK_VRM, MASK_VFADD_H | MASK_VRM, match_opcode,  0 },
{"vfadd.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFADD_H, MASK_VFADD_H, match_opcode,  0 },
{"vfsub.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFSUB_H | MASK_VRM, MASK_VFSUB_H | MASK_VRM, match_opcode,  0 },
{"vfsub.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFSUB_H, MASK_VFSUB_H, match_opcode,  0 },
{"vfmul.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFMUL_H | MASK_VRM, MASK_VFMUL_H | MASK_VRM, match_opcode,  0 },
{"vfmul.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFMUL_H, MASK_VFMUL_H, match_opcode,  0 },
{"vfdiv.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFDIV_H | MASK_VRM, MASK_VFDIV_H | MASK_VRM, match_opcode,  0 },
{"vfdiv.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFDIV_H, MASK_VFDIV_H, match_opcode,  0 },
{"vfsqrt.h",   "Xhwacha",   "#N,#p,#v,#w,#d,#s",  MATCH_VFSQRT_H | MASK_VRM, MASK_VFSQRT_H | MASK_VRM, match_opcode, 0 },
{"vfsqrt.h",   "Xhwacha",   "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFSQRT_H, MASK_VFSQRT_H, match_opcode, 0 },
{"vfmin.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFMIN_H, MASK_VFMIN_H, match_opcode,  0 },
{"vfmax.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFMAX_H, MASK_VFMAX_H, match_opcode,  0 },
{"vfmadd.h",   "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VFMADD_H | MASK_VRM, MASK_VFMADD_H | MASK_VRM, match_opcode,  0 },
{"vfmadd.h",   "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r,#m",  MATCH_VFMADD_H, MASK_VFMADD_H, match_opcode,  0 },
{"vfnmadd.h",  "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VFNMADD_H | MASK_VRM, MASK_VFNMADD_H | MASK_VRM, match_opcode,  0 },
{"vfnmadd.h",  "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r,#m",  MATCH_VFNMADD_H, MASK_VFNMADD_H, match_opcode,  0 },
{"vfmsub.h",   "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VFMSUB_H | MASK_VRM, MASK_VFMSUB_H | MASK_VRM, match_opcode,  0 },
{"vfmsub.h",   "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r,#m",  MATCH_VFMSUB_H, MASK_VFMSUB_H, match_opcode,  0 },
{"vfnmsub.h",  "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VFNMSUB_H | MASK_VRM, MASK_VFNMSUB_H | MASK_VRM, match_opcode,  0 },
{"vfnmsub.h",  "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r,#m",  MATCH_VFNMSUB_H, MASK_VFNMSUB_H, match_opcode,  0 },
{"vfcvt.s.h",  "Xhwacha",   "#N,#p,#v,#w,#d,#s",  MATCH_VFCVT_S_H, MASK_VFCVT_S_H | MASK_VRM, match_opcode,  0 },
{"vfcvt.h.s",  "Xhwacha",   "#N,#p,#v,#w,#d,#s",  MATCH_VFCVT_H_S | MASK_VRM, MASK_VFCVT_H_S | MASK_VRM, match_opcode,  0 },
{"vfcvt.h.s",  "Xhwacha",   "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_H_S, MASK_VFCVT_H_S, match_opcode,  0 },
{"vfcvt.d.h",  "Xhwacha",   "#N,#p,#v,#w,#d,#s",  MATCH_VFCVT_D_H, MASK_VFCVT_D_H | MASK_VRM, match_opcode,  0 },
{"vfcvt.h.d",  "Xhwacha",   "#N,#p,#v,#w,#d,#s",  MATCH_VFCVT_H_D | MASK_VRM, MASK_VFCVT_H_D | MASK_VRM, match_opcode,  0 },
{"vfcvt.h.d",  "Xhwacha",   "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_H_D, MASK_VFCVT_H_D, match_opcode,  0 },
{"vcmpfeq.h",  "Xhwacha",   "#N,#p,#x,#F,#s,#t",    MATCH_VCMPFEQ_H, MASK_VCMPFEQ_H, match_opcode, 0 },
{"vcmpflt.h",  "Xhwacha",   "#N,#p,#x,#F,#s,#t",    MATCH_VCMPFLT_H, MASK_VCMPFLT_H, match_opcode, 0 },
{"vcmpfle.h",  "Xhwacha",   "#N,#p,#x,#F,#s,#t",    MATCH_VCMPFLE_H, MASK_VCMPFLE_H, match_opcode, 0 },
{"vcmpfgt.h",  "Xhwacha",   "#N,#p,#x,#F,#t,#s",    MATCH_VCMPFLT_H, MASK_VCMPFLT_H, match_opcode, 0 },
{"vcmpfge.h",  "Xhwacha",   "#N,#p,#x,#F,#t,#s",    MATCH_VCMPFLE_H, MASK_VCMPFLE_H, match_opcode, 0 },
{"vfcvt.w.h",  "Xhwacha",   "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_W_H | MASK_VRM, MASK_VFCVT_W_H | MASK_VRM, match_opcode,  0 },
{"vfcvt.w.h",  "Xhwacha",   "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_W_H, MASK_VFCVT_W_H, match_opcode,  0 },
{"vfcvt.wu.h", "Xhwacha",   "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_WU_H | MASK_VRM, MASK_VFCVT_WU_H | MASK_VRM, match_opcode,  0 },
{"vfcvt.wu.h", "Xhwacha",   "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_WU_H, MASK_VFCVT_WU_H, match_opcode,  0 },
{"vfcvt.h.w",  "Xhwacha",   "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_H_W | MASK_VRM, MASK_VFCVT_H_W | MASK_VRM, match_opcode,   0 },
{"vfcvt.h.w",  "Xhwacha",   "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_H_W, MASK_VFCVT_H_W, match_opcode,   0 },
{"vfcvt.h.wu", "Xhwacha",   "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_H_WU | MASK_VRM, MASK_VFCVT_H_W | MASK_VRM, match_opcode,   0 },
{"vfcvt.h.wu", "Xhwacha",   "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_H_WU, MASK_VFCVT_H_WU, match_opcode,   0 },
{"vfcvt.l.h",  "Xhwacha",   "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_L_H | MASK_VRM, MASK_VFCVT_L_H | MASK_VRM, match_opcode,  0 },
{"vfcvt.l.h",  "Xhwacha",   "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_L_H, MASK_VFCVT_L_H, match_opcode,  0 },
{"vfcvt.lu.h", "Xhwacha",   "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_LU_H | MASK_VRM, MASK_VFCVT_LU_H | MASK_VRM, match_opcode,  0 },
{"vfcvt.lu.h", "Xhwacha",   "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_LU_H, MASK_VFCVT_LU_H, match_opcode,  0 },
{"vfcvt.h.l",  "Xhwacha",   "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_H_L | MASK_VRM, MASK_VFCVT_H_L | MASK_VRM, match_opcode,   0 },
{"vfcvt.h.l",  "Xhwacha",   "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_H_L, MASK_VFCVT_H_L, match_opcode,   0 },
{"vfcvt.h.lu", "Xhwacha",   "#N,#p,#v,#w,#d,#s",     MATCH_VFCVT_H_LU | MASK_VRM, MASK_VFCVT_H_L | MASK_VRM, match_opcode,   0 },
{"vfcvt.h.lu", "Xhwacha",   "#N,#p,#v,#w,#d,#s,#m",  MATCH_VFCVT_H_LU, MASK_VFCVT_H_LU, match_opcode,   0 },

/* Mixed-precision floating-point instruction subset */
{"vfadd.s.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFADD_S_H | MASK_VRM, MASK_VFADD_S_H | MASK_VRM, match_opcode,  0 },
{"vfadd.s.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFADD_S_H, MASK_VFADD_S_H, match_opcode,  0 },
{"vfsub.s.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFSUB_S_H | MASK_VRM, MASK_VFSUB_S_H | MASK_VRM, match_opcode,  0 },
{"vfsub.s.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFSUB_S_H, MASK_VFSUB_S_H, match_opcode,  0 },
{"vfmul.s.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFMUL_S_H | MASK_VRM, MASK_VFMUL_S_H | MASK_VRM, match_opcode,  0 },
{"vfmul.s.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFMUL_S_H, MASK_VFMUL_S_H, match_opcode,  0 },
{"vfadd.d.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFADD_D_H | MASK_VRM, MASK_VFADD_D_H | MASK_VRM, match_opcode,  0 },
{"vfadd.d.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFADD_D_H, MASK_VFADD_D_H, match_opcode,  0 },
{"vfsub.d.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFSUB_D_H | MASK_VRM, MASK_VFSUB_D_H | MASK_VRM, match_opcode,  0 },
{"vfsub.d.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFSUB_D_H, MASK_VFSUB_D_H, match_opcode,  0 },
{"vfmul.d.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFMUL_D_H | MASK_VRM, MASK_VFMUL_D_H | MASK_VRM, match_opcode,  0 },
{"vfmul.d.h",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFMUL_D_H, MASK_VFMUL_D_H, match_opcode,  0 },
{"vfmadd.d.h",   "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VFMADD_D_H | MASK_VRM, MASK_VFMADD_D_H | MASK_VRM, match_opcode,  0 },
{"vfmadd.d.h",   "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r,#m",  MATCH_VFMADD_D_H, MASK_VFMADD_D_H, match_opcode,  0 },
{"vfnmadd.d.h",  "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VFNMADD_D_H | MASK_VRM, MASK_VFNMADD_D_H | MASK_VRM, match_opcode,  0 },
{"vfnmadd.d.h",  "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r,#m",  MATCH_VFNMADD_D_H, MASK_VFNMADD_D_H, match_opcode,  0 },
{"vfmsub.d.h",   "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VFMSUB_D_H | MASK_VRM, MASK_VFMSUB_D_H | MASK_VRM, match_opcode,  0 },
{"vfmsub.d.h",   "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r,#m",  MATCH_VFMSUB_D_H, MASK_VFMSUB_D_H, match_opcode,  0 },
{"vfnmsub.d.h",  "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VFNMSUB_D_H | MASK_VRM, MASK_VFNMSUB_D_H | MASK_VRM, match_opcode,  0 },
{"vfnmsub.d.h",  "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r,#m",  MATCH_VFNMSUB_D_H, MASK_VFNMSUB_D_H, match_opcode,  0 },
{"vfadd.d.s",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFADD_D_S | MASK_VRM, MASK_VFADD_D_S | MASK_VRM, match_opcode,  0 },
{"vfadd.d.s",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFADD_D_S, MASK_VFADD_D_S, match_opcode,  0 },
{"vfsub.d.s",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFSUB_D_S | MASK_VRM, MASK_VFSUB_D_S | MASK_VRM, match_opcode,  0 },
{"vfsub.d.s",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFSUB_D_S, MASK_VFSUB_D_S, match_opcode,  0 },
{"vfmul.d.s",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VFMUL_D_S | MASK_VRM, MASK_VFMUL_D_S | MASK_VRM, match_opcode,  0 },
{"vfmul.d.s",    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t,#m",  MATCH_VFMUL_D_S, MASK_VFMUL_D_S, match_opcode,  0 },

/*new rvv instructions*/
{"vmerge"   ,    "Xhwacha",   "#N,#p,#v,#w,#x,#d,#s,#t,#Q",  MATCH_VMERGE, MASK_VMERGE, match_opcode,  0 },
{"vmadd"    ,    "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VMADD, MASK_VMADD, match_opcode,  0 },
{"vmsub"    ,    "Xhwacha",   "#N,#p,#v,#y,#d,#s,#t,#r",  MATCH_VMSUB, MASK_VMSUB, match_opcode,  0 },
{"vclipw"   ,    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VCLIPW, MASK_VCLIPW, match_opcode,  0 },
{"vcliph"   ,    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VCLIPH, MASK_VCLIPH, match_opcode,  0 },
{"vclipb"   ,    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VCLIPB, MASK_VCLIPB, match_opcode,  0 },
{"vmax"     ,    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VMAX, MASK_VMAX, match_opcode,  0 },
{"vmaxu"    ,    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VMAXU, MASK_VMAXU, match_opcode,  0 },
{"vmin"     ,    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VMIN, MASK_VMIN, match_opcode,  0 },
{"vminu"    ,    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VMINU, MASK_VMINU, match_opcode,  0 },
{"vsetxrm"  ,    "Xhwacha",   "d,s",  MATCH_VSETXRM, MASK_VSETXRM, match_opcode,  0 },
{"vgetxrm"  ,    "Xhwacha",   "d",  MATCH_VGETXRM, MASK_VGETXRM, match_opcode,  0 },
{"vsetxsat" ,    "Xhwacha",   "d,s",  MATCH_VSETXSAT, MASK_VSETXSAT, match_opcode,  0 },
{"vgetxsat" ,    "Xhwacha",   "d",  MATCH_VGETXSAT, MASK_VGETXSAT, match_opcode,  0 },

{"vredsum"  ,    "Xhwacha",   "#N,#p,#v,#x,#d,#s,#t",  MATCH_VREDSUM, MASK_VREDSUM, match_opcode,  0 },

/* Multi-dimensional stuff */
{"vfvmmadd.h",   "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r,#L",  MATCH_VFVMMADD_H | MASK_VRM, MASK_VFVMMADD_H | MASK_VRM, match_opcode,   0 },
{"vfvmmadd.h",   "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r,#L,#m",  MATCH_VFVMMADD_H, MASK_VFVMMADD_H, match_opcode,   0 },
{"vfvmmadd.s",   "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r,#L",  MATCH_VFVMMADD_S | MASK_VRM, MASK_VFVMMADD_S | MASK_VRM, match_opcode,   0 },
{"vfvmmadd.s",   "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r,#L,#m",  MATCH_VFVMMADD_S, MASK_VFVMMADD_S, match_opcode,   0 },
{"vfvmmadd.d",   "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r,#L",  MATCH_VFVMMADD_D | MASK_VRM, MASK_VFVMMADD_D | MASK_VRM, match_opcode,   0 },
{"vfvmmadd.d",   "Xhwacha", "#N,#p,#v,#y,#d,#s,#t,#r,#L,#m",  MATCH_VFVMMADD_D, MASK_VFVMMADD_D, match_opcode,   0 },

{"vldd",       "Xhwacha", "#N,#p,#d,#A,#L", MATCH_VLDD, MASK_VLDD, match_opcode, 0},

/* Terminate the list.  */
{0, 0, 0, 0, 0, 0, 0}

};
