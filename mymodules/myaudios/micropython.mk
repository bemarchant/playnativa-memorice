MYMODULE_MOD_DIR := $(USERMOD_DIR)

# Add all C files to SRC_USERMOD.
SRC_USERMOD += $(MYMODULE_MOD_DIR)/audiodata.c

# We can add our module folder to include paths if needed
# This is not actually needed in this example.
CFLAGS_USERMOD += -I$(MYMODULE_MOD_DIR)
MYMODULEC_MOD_DIR := $(USERMOD_DIR)
