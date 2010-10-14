Name:		flip
Version:	0.2
Release:	1%{?dist}
Summary:	rotate characters 180 degrees

Group:		Applications/Text
License:	GPLv3

Source0:	%{name}-%{version}.tar.gz
BuildRoot:	%(mktemp -ud %{_tmppath}/%{name}-%{version}-%{release}-XXXXXX)

BuildRequires:	gcc

%description
Transforms text on stdin by rotating each character
180 degrees, essentially flipping each character upside down.


%prep
%setup -q


%build
gcc src/flip.c -o flip


%install
%{__rm} -rf %{buildroot}
%{__mkdir_p} %{buildroot}%{_bindir}
%{__install} -pm 755 flip %{buildroot}%{_bindir}


%clean
%{__rm} -rf %{buildroot}


%files
%defattr(-,root,root,-)
%{_bindir}/flip
%doc src/flip.c
%doc COPYING



%changelog
* Thu Oct 14 2010 Paul Morgan <jumanjiman@gmail.com> 0.2-1
- fix wprintf: Illegal seek (msciabica@ise.com)

* Thu Oct 14 2010 Paul Morgan <jumanjiman@gmail.com> 0.1-1
- new package built with tito


