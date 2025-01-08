SRC += oxinai.c \
      process_records.c

ifeq ($(strip $(QMKRC_ENABLE)), yes)
	SRC += qmk_rc.c
	RAW_ENABLE = yes
endif
UNICODE_COMMON ?= yes
UNICODE_ENABLE ?= yes
KEYLOGGER_ENABLE ?= no
ifdef CONSOLE_ENABLE
    ifeq ($(strip $(KEYLOGGER_ENABLE)), yes)
        OPT_DEFS += -DKEYLOGGER_ENABLE
    endif
endif

ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
  SRC += secrets.c
endif

EXTRAFLAGS += -flto

ifeq ($(strip $(NO_SECRETS)), yes)
    OPT_DEFS += -DNO_SECRETS
endif

AUTOCORRECT_ENABLE ?= yes

CAPS_WORD ?= no
ifeq ($(strip $(CAPS_WORD)), yes)
	SRC += caps_word.c
endif

SELECT_WORD ?= no
ifeq ($(strip $(CAPS_WORD)), yes)
	SRC += select_word.c
endif


LTO_ENABLE ?= yes
