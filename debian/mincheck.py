
import sys
from sets import Set as set

def get_listed(fn):
    modules = set()
    for line in file(fn).readlines():
        modules.add(line.split()[1])
    return modules

def get_dependencies(fn):
    t = eval(file(fn).read())
    modules = set()
    depgraph = t['depgraph']
    for mod, deps in depgraph.iteritems():
        if mod != '__main__':
            modules.add(mod)
        modules.update(deps.keys())
    return depgraph, modules

def main():
    mods = get_listed(sys.argv[1])
    depgraph, deps = get_dependencies(sys.argv[2])
    print "Listed modules:", mods
    print "Dependent modules:", deps

    missing = deps.difference(mods)
    if missing:
        print "Missing modules in python-minimal:"
        print missing
    for m in missing:
        users = []
        for caller, callees in depgraph.iteritems():
            if m in callees:
                users.append(caller)
        print m, "used in: ", users
    sys.exit(len(missing))

main()

