## Build and install

```bash
$ meson setup _ --prefix=/usr
$ meson compile -C _
$ meson install -C _
```

## To reproduce

```bash
# Reply expected
$ systemctl stop dbus-issue-562
$ busctl call --system dev.glazkov.DBusIssue562 / dev.glazkov.DBusIssue562 CallUnknownMethod

# Reply not expected
$ systemctl stop dbus-issue-562
$ busctl call --expect-reply=no --system dev.glazkov.DBusIssue562 / dev.glazkov.DBusIssue562 CallUnknownMethod
```
