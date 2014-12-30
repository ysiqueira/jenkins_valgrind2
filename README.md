This Subversion repository was created as an experiment to learn more
about the Jenkins valgrind plugin.

The code samples attempt to keep a distinct number of each type of
warning so that the user can confirm they are seeing all the expected
warnings.

A Jenkins job definition file is included as an XML file in the
directory. The Jenkins job and the Makefile have been verified on 64
bit Debian Wheezy, 64 bit Oracle Linux 6.0, and 32 bit Debian Wheezy.

The valgrind plugin does not work as well in a multi-configuration job
as other plugins. The results of a job are not displayed graphically
in any of the configurations, though the tables are preserved. The
simplest solution to that is to avoid multi-configuration jobs and
create individual jobs instead.

There is no way to specify arguments to the programs executed by the
plugin.

Pre-steps to run the program in valgrind require a separate build step
prior to the valgrind step.


