qt5 = import('qt5')
qt5_dep = dependency('qt5', modules: ['Core', 'DBus'])

src = ['main.cpp']
moc = qt5.compile_moc(sources: src)

executable('dbus-issue-562', src, moc, dependencies: qt5_dep, install: true)
