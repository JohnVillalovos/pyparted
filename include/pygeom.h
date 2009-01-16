/*
 * pygeom.h
 * pyparted type definitions for pygeom.c
 *
 * Copyright (C) 2007, 2008 Red Hat, Inc.
 *
 * This copyrighted material is made available to anyone wishing to use,
 * modify, copy, or redistribute it subject to the terms and conditions of
 * the GNU General Public License v.2, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY expressed or implied, including the implied warranties of
 * MERCHANTABILITY or FITNESS FOR A * PARTICULAR PURPOSE.  See the GNU General
 * Public License for more details.  You should have received a copy of the
 * GNU General Public License along with this program; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.  Any Red Hat trademarks that are incorporated in the
 * source code or documentation are not subject to the GNU General Public
 * License and may only be used or replicated with the express permission of
 * Red Hat, Inc.
 *
 * Red Hat Author(s): David Cantrell <dcantrell@redhat.com>
 *                    Chris Lumens <clumens@redhat.com>
 */

#ifndef PYGEOM_H_INCLUDED
#define PYGEOM_H_INCLUDED

#include <Python.h>

#include <parted/parted.h>

/* 1:1 function mappings for geom.h in libparted */
PyObject *py_ped_geometry_duplicate(PyObject *s, PyObject *args);
PyObject *py_ped_geometry_intersect(PyObject *s, PyObject *args);
PyObject *py_ped_geometry_set(PyObject *s, PyObject *args);
PyObject *py_ped_geometry_set_start(PyObject *s, PyObject *args);
PyObject *py_ped_geometry_set_end(PyObject *s, PyObject *args);
PyObject *py_ped_geometry_test_overlap(PyObject *s, PyObject *args);
PyObject *py_ped_geometry_test_inside(PyObject *s, PyObject *args);
PyObject *py_ped_geometry_test_equal(PyObject *s, PyObject *args);
PyObject *py_ped_geometry_test_sector_inside(PyObject *s, PyObject *args);
PyObject *py_ped_geometry_read(PyObject *s, PyObject *args);
PyObject *py_ped_geometry_sync(PyObject *s, PyObject *args);
PyObject *py_ped_geometry_sync_fast(PyObject *s, PyObject *args);
PyObject *py_ped_geometry_write(PyObject *s, PyObject *args);
PyObject *py_ped_geometry_check(PyObject *s, PyObject *args);
PyObject *py_ped_geometry_map(PyObject *s, PyObject *args);

/* _ped.Geometry type is the Python equivalent of PedGeometry in libparted */
typedef struct {
    PyObject_HEAD

    /* PedGeometry members */
    PyObject *dev;                /* _ped.Device */
    long long start;              /* PedSector   */
    long long length;             /* PedSector   */
    long long end;                /* PedSector   */

    /* store the PedDevice pointer */
    PedDevice *ped_device;
} _ped_Geometry;

void _ped_Geometry_dealloc(_ped_Geometry *self);
int _ped_Geometry_traverse(_ped_Geometry *self, visitproc visit, void *arg);
int _ped_Geometry_clear(_ped_Geometry *self);
int _ped_Geometry_init(_ped_Geometry *self, PyObject *args, PyObject *kwds);
PyObject *_ped_Geometry_get(_ped_Geometry *self, void *closure);
int _ped_Geometry_set(_ped_Geometry *self, PyObject *value, void *closure);

extern PyTypeObject _ped_Geometry_Type_obj;

#endif /* PYGEOM_H_INCLUDED */

/* vim:tw=78:ts=4:et:sw=4
 */
