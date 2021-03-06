/*
 * Copyright (C) 2019 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 *
 */

#include "config.h"

#include "compositor/meta-compositor-server.h"

G_DEFINE_TYPE (MetaCompositorServer, meta_compositor_server, META_TYPE_COMPOSITOR)

static gboolean
meta_compositor_server_manage (MetaCompositor  *compositor,
                               GError         **error)
{
  return TRUE;
}

static void
meta_compositor_server_unmanage (MetaCompositor *compositor)
{
}

MetaCompositorServer *
meta_compositor_server_new (MetaDisplay *display,
                            MetaBackend *backend)
{
  return g_object_new (META_TYPE_COMPOSITOR_SERVER,
                       "display", display,
                       "backend", backend,
                       NULL);
}

static void
meta_compositor_server_init (MetaCompositorServer *compositor_server)
{
}

static void
meta_compositor_server_class_init (MetaCompositorServerClass *klass)
{
  MetaCompositorClass *compositor_class = META_COMPOSITOR_CLASS (klass);

  compositor_class->manage = meta_compositor_server_manage;
  compositor_class->unmanage = meta_compositor_server_unmanage;
}
