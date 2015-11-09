package.path = '/usr/local/lib/SPRITE/?.lua;' .. package.path
local s = require 'scheduler'

--------------------------------------------------------------------------------
-- Set some script constants
--------------------------------------------------------------------------------

HELLO_NTIMES = 10

--------------------------------------------------------------------------------
-- Initialize the tasks.
--------------------------------------------------------------------------------

-- Create task properties and set an initial priority.
tp = Task_properties.new()
priority = tp:MAX_USER_TASK_PRIO()

-- Create the scheduler.
SCHEDULER_PERIOD = s.HZ_to_period(1)
scheduler = s.create(tp, SCHEDULER_PERIOD, priority)
priority = priority - 1

-- Create the hello world task.
hello = Hello.new("Hello", HELLO_NTIMES)
s.set_task_properties(hello, tp, SCHEDULER_PERIOD, priority)
priority = priority - 1

--------------------------------------------------------------------------------
-- Start up the tasks.
--------------------------------------------------------------------------------

-- Start everything up.
print "Starting tasks..."
scheduler:start()
hello:start()

-- Use debug to pause the script and let the tasks run.
print "Use control-D to cleanly terminate execution."
debug:debug()

--------------------------------------------------------------------------------
-- Terminate the tasks.
--------------------------------------------------------------------------------

print "...Exiting"

hello:stop()
scheduler:stop()
